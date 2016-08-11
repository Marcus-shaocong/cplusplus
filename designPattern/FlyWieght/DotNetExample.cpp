

public class StoneTile.ITile
{
  public static int ObjectCounter = 0;
  Brush paintBrush;

  
  public StoneTile()
  {
    paintBrush = Brushes.Blue;

    ++ObjectCounter;
  }

  public void Draw(Graphics g, int x, int y, int width, int height)
  {
    g.FillRectangle(paintBrush, x, y, width, height); 
  }

}

public class TileFactory
{
  //Flywight pattern is to store all the instance.
  static Dictionary<string, ITile> tiles = new Dictionary<string, ITile>();
  public static ITile GetTile(string tileType)
  {
    switch(tileType)
    {
      case "Ceramic":
        if(!tiles.ContainsKey("Ceramic"))
          tiles["Ceramic"] = new Ceramictile();
          return tiles["Ceramic"];
      case "Stone":
        if(!tiles.ContainsKey("Stone"))
          tiles["Stone"] = new Ceramictile();
          return tiles["Stone"];
      default:
          break;
    }
    return null;
  }


}


main()
{
    ITile ceramicTile=TileFactory.GetTile("Ceramic");
    ceramicTile.Draw(e.Graphics,GetRandomNumber(),GetRandomNumber(),GetRandomNumber(),GetRandomNumber());

}
