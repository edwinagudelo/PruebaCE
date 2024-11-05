#pragma once

using namespace System;
using namespace System::Data;

namespace Infrastructure {

	public delegate System::Void exportProgress(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);

	public interface class IExportService
	{
	public:
		IExportService^ SetData(DataTable^ data);
		IExportService^ SetPath(String^ path);
		IExportService^ SetFilename(String^ filename);
		int Export();
		void CancelExport();
		event exportProgress^ ProgressReportEvent;
	};

}
