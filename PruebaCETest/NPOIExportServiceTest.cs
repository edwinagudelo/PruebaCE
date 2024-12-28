using Infrastructure;
using log4net;
using log4net.Appender;
using log4net.Config;
using System.Data;

namespace PruebaCETest
{
    public class NPOIExportServiceTest
    {
        private IExportService exportService;
        private static ILog _logger = LogManager.GetLogger(typeof(NPOIExportServiceTest));

        public NPOIExportServiceTest()
        { 
            var appender = new ConsoleAppender();
            BasicConfigurator.Configure(appender);
            exportService = new NPOIExportService();
        }


        [Fact]
        public void ExportTest()
        {
            // Arrange
            DataTable dataTable = setUpDataTable();
            string temppath = Path.GetTempPath();
            string tempname = "avengers.xlsx";
            exportService.SetData(dataTable);
            exportService.SetPath(temppath);
            exportService.SetFilename(tempname);

            // Act
            var result = exportService.Export();

            // Assert
            Assert.Equal(dataTable.Rows.Count, result);
        }

        #region private methods
        private DataTable setUpDataTable()
        {
            DataTable dataTable = null;
            try
            {
                dataTable = new DataTable("testdata");
                dataTable.Columns.Add(new DataColumn("id", Type.GetType("System.Int32")));
                dataTable.Columns.Add(new DataColumn("name", Type.GetType("System.String")));
                DataRow dr = dataTable.NewRow();
                dr["id"] = 1;
                dr["name"] = "Tony Stark";
                dataTable.Rows.Add(dr);
                return dataTable;
            }
            catch (Exception ex)
            {
                _logger.ErrorFormat("Error creating test data:{0}", ex);
                dataTable = null;
            }
            return dataTable;
        }
        #endregion
    }
}