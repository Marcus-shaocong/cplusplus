

// Interface segregation Principle(ISP)
//
// No client should be forced to depend on methods it does not use
// For instance, a client want to have a couple of operations to deal
// with the document. like print, scan, fax.
//


struct Document;


// client might not need all these interfaces, so want to 
// seperate these functions. 
// this is a bad design to put all the function in one class 
// because user would not need so manhy functions.
struct IMachine
{
virtual void print(std::vector<Document*> docs) = 0;
virtual void scan(std::vector<Document*> docs) = 0;
virtual void fax(std::vector<Document*> docs) = 0;
};

struct MFP: IMachine
{
void print(std::vector<Document*> docs) override;
void scan(std::vector<Document*> docs) override;
void fax(std::vector<Document*> docs) override;
}


// a good design is to seperate the interface into different class
struct IPrinter
{
  virtual void print(std::vector<Document*> docs) = 0;
};
struct IScanner 
{
  virtual void scan(std::vector<Document*> docs) = 0;
};

struct IFax
{
  virtual void fax(std::vector<Document*> docs) = 0;
};

struct Printer: public IPrinter
{
  void print(std::vector<Document*> docs) override; 
}

struct Scanner: public IScanner
{
  void scan(std::vector<Document*> docs) override; 
}

// if user want to have all function, they can have multi-inheritance
struct IMachine: IPrinter, IScanner {};

struct Machine : IMachine
{
  IPrinter & printer;
  IScanner & scanner
  Machine(IPrinter & printer, IScanner & scanner)
  :printer(printer), scanner(scanner)
  {
  }
  void print(std::vector<Document*> docs) override
  {
    printer.print(docs);
  
  }
  void scan(std::vector<Document*> docs) override
  {
    scanner.scan(docs); 
  }
};
