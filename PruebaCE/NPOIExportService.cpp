#include "stdafx.h"
#include "NPOIExportService.h"

using namespace Infrastructure;

NPOIExportService::~NPOIExportService() {
	if (_data != nullptr) {
		_data->Clear();
	}
	_logger->Info("Finishing NpoiExportService");
}

IExportService^ NPOIExportService::SetData(DataTable^ data) {
	_data = data;
	return this;
}

IExportService^ NPOIExportService::SetPath(String^ path) {
	_path = path;
	return this;
}

IExportService^ NPOIExportService::SetFilename(String^ filename) {
	_filename = filename;
	return this;
}

int NPOIExportService::Export() {
	int rowsexp = 0;
	_logger->Info("Starting Export");

	this->ProgressReportEvent += gcnew exportProgress(this, &NPOIExportService::reportprogress);

	// TODO: data validation

	try {
		IWorkbook^ workbook = createfile();
		if (workbook == nullptr) {
			throw gcnew ArgumentException("Invalid extension");
		}
		ISheet^ sheet = workbook->CreateSheet(_data->TableName);
		writeheaders(sheet, workbook);
		int irow = 1;
		for each (DataRow ^ dr in _data->Rows) {
			IRow^ row = sheet->CreateRow(irow);
			int icol = 0;
			for each (DataColumn^ col in _data->Columns) {
				ICell^ cell = row->CreateCell(icol);
				setcelltype(col, cell);
				cell->SetCellValue(dr[icol]->ToString());
				icol++;
			}
			irow++;
		}
		rowsexp = irow - 1;

		String^ finalname = _path + Path::DirectorySeparatorChar + _filename;
		FileStream^ fs = gcnew FileStream(finalname, FileMode::Create);
		_logger->InfoFormat("Exporting data to {0}", finalname);
		workbook->Write(fs, false);
	}
	catch (Exception^ ex) {
		_logger->ErrorFormat("Error exporting rows {0}", ex->Message);
	}
	_logger->InfoFormat("Exported {0}", rowsexp);
	return rowsexp;
}

#pragma region private methods

IWorkbook^ NPOIExportService::createfile() {
	IWorkbook^ result = nullptr;
	String^ extension = Path::GetExtension(_filename);
	if (extension == ".xlsx") {
		result = gcnew XSSFWorkbook();
	}
	else if (extension == ".xls") {
		result = gcnew HSSFWorkbook();
	}
	else {
		_logger->ErrorFormat("{0} extension is not supported", extension);
	}
	return result;
}

void NPOIExportService::writeheaders(ISheet^ sheet, IWorkbook^ wb) {
	IRow^ rowh = sheet->CreateRow(0);
	int icol = 0;
	
	IFont^ font = wb->CreateFont();
	font->IsBold = true;
	ICellStyle^ style = wb->CreateCellStyle();
	style->SetFont(font);

	for each (DataColumn^ col in _data->Columns) {
		ICell^ cell = rowh->CreateCell(icol);
		cell->SetCellValue(col->ColumnName);
		cell->CellStyle = style;
		icol++;
	}
}

void NPOIExportService::setcelltype(DataColumn^ col, ICell^ cell) {
	String^ strtype = col->DataType->GetType()->Name->ToLower();
	if (strtype->Contains("int") || strtype->Contains("single") || strtype->Contains("date") || strtype->Contains("time") || strtype->Contains("byte")) {
		cell->SetCellType(CellType::Numeric);
	}
	else  {
		cell->SetCellType(CellType::String);
	}
}

System::Void NPOIExportService::reportprogress(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	_logger->InfoFormat("Advance:{0}",e->ProgressPercentage);
}

#pragma endregion
