
//
// This is an example from the .net programming, but
// becaues patterns are independent from language. The 
// example itself is a very good learning material to
// learn the Adapter pattern.
//
//

public class DataRenderenShould
{
  // This is the main test program to test the Adapter
  public void RenderOneRowGivenStubDataAdapter()
  {
    var myRenderer = new DataRenderer(new StubDbAdapter());
    var writer = new StringWriter();
    myRenderer.Render(writer);
    string result = writer.ToString();
    Console.Write(result);

    int lineCount = result.Cout(c=>c=='\n');
    Assert.AreEqual(3,lineCount);
  }
}

public class PatternRendererShould
{
    public void RenderOnePattern()
    {
      var myRenderer = new PatternRenderer();
      var myList = new List><Pattern>
      {
        new Pattern{Id=1, Name="Pattern One", Description="patern One description"},
        new Pattern{Id=2, Name="Pattern two", Description="patern two description"},
      };

      string result = myRenderer.ListPatterns(myList);
      Console.Write(result);
      int lineCount = result.Count(c=>c=='\n');
      Assert.AreEqual(myList.Count + 2, lineCount);
    }
}



public class StubDbAdapter: IDbDataAdapter
{

    public DataTable[] FillSchema(DataSet dataSet, SchemaType schemaType)
    {
      throw new NotImplementedException();  
    } 

    public int Fill(DataSet dataSet)
    {
      var myDataTable = new DataTable();
      myDataTable.Columns.Add(new DataColumn("Id",typeod(int)));
      myDataTable.Columns.Add(new DataColumn("Name",typeod(string)));
      myDataTable.Columns.Add(new DataColumn("Description",typeod(string)));

     var myRow = myDataTable.NewRow();
     myRow[0] = 1;
     myRow[1] = "Adapter";
     myRow[2] = "Adapter description";
     myDataTable.Rows.add(myRow);
     dataSet.Tables.add(myDataTable);
     dataSet.AcceptChanges();
    }
}

public class DataRenderer
{
    private readonly IDbDataAdapter _dataAdapter;
    public DataRenderer(IDbDataAdapter dataAdapter)
    {
      _dataAdapter = dataAdapter; 
    }


  public void Render(TextWriter writer)
  {
  
    writer.WriteLine("Rendering Data:");
    var my DataSet = new DataSet();

    _dataAdapter.Fill(myDataSet);
    foreach(DataTable table in myDataSet.Tables)
    {
      foreach(DataColumn column in table.Columns)
      {
        writer.Write(column.ColumnName.PadRight(20)+" "); 
      }
      writer.WriteLine();
      foreach(DataRow row in table.Rows)
      {
          for(int i=0; i<table.Columns.Count, i++)
          {
            writer.Write(row[i].ToString().PadRight(20)+" "); 
          }
          writer.WriteLine();
      }
    
    }
  }
}


public class PatternRenderer
{
    private readonly IDataPatternRendererAdapter _dataPatternRenderer;

    public patternRenderer(IDataPatternRendererAdapter dataPatternRenderer)
    {
      _dataPaternRenderer = dataPatternRenderer;
    }
  
    public PatternRenderer():this(new DataPatternRendererAdapter())
    {

    }

    public string ListPatterns(IEnumerable<Pattern> patterns)
    {
        return _dataPatternRenderer.ListPatterns(patterns);  
    }

    //deifne a internal interface as Adapter
    public interface IDataPatternRendererAdapter 
    {
      string ListPatterns(IEnumerable<Pattern> patterns); 
    }

    class DataPatternRendererAdapter: IDataPatternRendererAdapter 
    {
      private DataRenderer _dataRenderer;
      
      public string ListPatterns(IEnumerable<Pattern> patterns)
      {
        var adapter = new PatternCollectionDbAdapter(patterns);

        _dataRenderer = new DataRenderer(); 
        var writer = new StringWriter();
        _dataRenderer.Render(writer);
        return writer.ToString();
      }
      
      internal class PatternCollectionDbAdapter: IDbDataAdapter
      {
        private readonly IEnumerable<Pattern> _patterns;

        public PatternCollectionDbAdapter(IEnumerable<Pattern>  patterns)
        {
          _patterns = paterns; 
        }

        public int Fill(DataSet dataSet)
        {
          var myDataTable = new DataTable();
          myDataTable.Columns.Add(new DataColumn("Id",typeod(int)));
          myDataTable.Columns.Add(new DataColumn("Name",typeod(string)));
          myDataTable.Columns.Add(new DataColumn("Description",typeod(string)));

          foreach (var pattern in _patterns)
          {
            var myRow = myDataTable.NewRow();
            myRow[0] = pattern.Id;
            myRow[1] = pattern.Name;
            myRow[2] = pattern.Description;
            myDataTable.Rows.Add(myRow);
          }
          dataSet.Tables.Add(myDataTable);
          dataSet.AcceptChanges();
          return myDataTable.Rows.Count; 
        }
      
      }
    }
}


