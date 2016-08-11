namespace Poker
{
  abstract class HandCatagorizer
  {
    public HandCatagorizer RegisterNext(   HandCatagorizer  next)
    {
      Next = next;
      return Next;
    } 
   
    protected HandCatagorizer Next {get, private set;}

    public abstract HandRanking Catagorize(Hand hand);

    protected static bool HasNofKind(int n, Hand hand);

    protected static bool HasStraight(Hand hand)
    {
      List<Value> values = hand.Cards.Select(c=>c.Value).ToList();
      values.Sort();
      int expectedVAlue= (int)values[0];

      foreach(Value value in values)
      {
        if((int)value != expectedValue)
        {
        
        }
      }
    }



  } // end of class
  
} //end of namespace


class HighCardCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}

class PairCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    if(HasNofKind(2, hand))
    {
      return HandRanking.Pair; 
    } 
    return Next.Catagorize(hand); 
  }
}


class TwoPairCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}


class ThreeOfAKindCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}

class StraightCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}
class FlushCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}
class FullHouseCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}
class FourOfAKindCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    return HandRanking.HighCard; 
  }
}
class StraightFlushCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    if(HasFlush(hand) && HasStraight(hand) )
    {
      return HandRanking.RoyalFlush;
    }
    return Next.Catagorize(hand); 
  }
}

class RoyalFlushCatagorizer: HandCatagorizera
{
  public override HandRanking Catagorizer(hand hand)
  {
    if(HasFlush(hand) && HasStraight(hand) && hand.HighCard.Value == Value.Ace)
    {
      return HandRanking.RoyalFlush;
    }
    return Next.Catagorize(hand); 
  }
}
