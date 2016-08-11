

class HandCatagorizerChain
{
    private HandCatagorizerChain()
    {
      Head = new RoyalFlushCatagorizer();
      Head.RegisterNext(new StraightFlushCatagorizer())
        .RegisterNext(new FourOfAkindCatagorizer())
        .RegiesterNext(new FullHouseCatagorizer())
        .RegiesterNext(new FlushCatagorizer())
        .RegiesterNext(new StraightCatagorizer())
        .RegiesterNext(new ThreeOfAKindCatagorizer())
        .RegiesterNext(new TwoPairCatagorizer())
        .RegiesterNext(new PairCatagorizer())
        .RegiesterNext(new HighCardCatagorizer());
    
    }

    public static HandRanking GetRank(Hand hand)
    {
      return _instance.Head.Catagorize(hand); 
    }

    private HandCatagorizer Head{get, set;}

    private static HandCatagorizerChain _instance = new HandCatagorizerChain();
}
