namespace Poker
{


  class Hand
  {
      private readonly List<Card> _cards = new List<Card>(); 
      private HandRanking _rank = HandRanking.Unknown;

      public void Add(Card c)
      {
        if(_cards.Count == 5 )
        {
            throw new IvalidOperationException("Cannot add more than 5 cards to a hand."); 
        }
        
        _cards.Add(c);

        if(_cards.Count == 5)
        {
          //chain of responsibility by class HandCatagorizerChain
          _rank = HandCatagorizerChain.GetRank(this); 
         }

        public Card HighCard
        {
          get
          {
            if(_cards.Count == 0)
            {
              throw new InvalidOperationException(); 
            }
            return _cards[_cards.Count - 1]; 
          }
        }

        public IEnumerable<Card> Cards
        {
            get{ return _cards;} 
        }

        public HandRanking Rank
        {
          get {return _rank;} 
        }

        public override string ToString()
        {
          StringBuilder sb = new StringBuilder();
          foreach(Card c in _cards)
          {
            sb.AppendFormat("{0}" ,c); 
          }
          return sb.ToString(); 
        }
      }
  
  }

}
