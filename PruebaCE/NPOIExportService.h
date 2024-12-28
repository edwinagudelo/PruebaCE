#pragma once
#include "IExportService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::IO;
using namespace System::Threading;

using namespace log4net;
using namespace NPOI;
using namespace NPOI::SS::UserModel;
using namespace NPOI::HSSF::UserModel;
using namespace NPOI::XSSF::UserModel;

namespace Infrastructure {

	public ref class NPOIExportService : public IExportService
	{
	
	public:

		NPOIExportService() : _data(nullptr), _path(""), _filename("export.xlsx"), _cancelProcess(false) {}
		~NPOIExportService();

		virtual IExportService^ SetData(DataTable^ data);
		virtual IExportService^ SetPath(String^ path);
		virtual IExportService^ SetFilename(String^ filename);
		virtual int Export();
		virtual void CancelExport();
		virtual event exportProgress^ ProgressReportEvent;

	private:
		DataTable^ _data;
		String^ _path;
		String^ _filename;
		bool _cancelProcess;
		IWorkbook^ createfile();
		void writeheaders(ISheet^ sheet, IWorkbook^ wb);
		void setcelltype(DataColumn^ col, ICell^ cell);
		System::Void reportprogress(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);

		static ILog^ _logger = LogManager::GetLogger("NPOIExportService");
	};
}


