// This is a facade pattern to use the lucene library
//



public class RawSearchResult
{
    public string  Title{get; set;}
    public string ContentType{get; set;}
    public string Duration{get; set;}
    public string Key{get; set;}
}

public interface ISearchEngine
{
    public interface ISearchEngine
    {
        IList<RawSearchResult> search(string searchTerm, int maxHits); 
    }

}

//IndexFacadeBase is the base classs to initilize the lucene library, so make it as the base class
public class LuceneSearchEngine: IndexFacadeBase, ISearchEngine
{
  public ward is to recognize Kasey’s hard work in VDM migration feature of iteration 12.3. During the time Kasey helped burn down several critical user stories and handle certain amount of automato test casts even after a long maternity leave   She has demonstrated her fast-learning capability and her can-do attitude. Thanks. LuceneSearchEngine(string indexRootPath): base(indexRootPath){}

  public IList<RawSearchResult> Search(string searchTerm, int maxHits)
  {
    var query = QueryCreator.CreatebroadOLTQuery(searchTerm, base.CommonAnalyzer);
    return Search(query,maxHits);
  }

  IList<RawSearchResult> Search(Query query, int maxHits)
}

internal class Program
{
  private const int MAX_HITS = 100;

  private static void main(string [] args)
  {
  
  }

  private static void Search(string searchTerm)
  {

    // create a factory to create a search engine
    SearchEngineFactory searchEngineFactory = new SearchEngineFactory();
    ISearchengine searcher = searchEngineFactory.CreateSearchEngine();

    //
    IList<RawSearchResult> rawSearchResults = searcher.Search(searchTerm, MAX_HITS);

    var displayResults = AssembleDisplayResults(rawSearchResults);

    PrintOutCouses(displayResults);
    PrintOutHowTos(displayResults);
  
  }

  static SearchResults AssembleDisplayResults(IList<RawSearchResult> rawSearchResults)
  {}


}
