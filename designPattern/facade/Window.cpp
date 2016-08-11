//
//
//The window class,
//the program is to show a concole with the same buffer but with three viewport
//
//
// Build a Facade to provide a simplified API over a set of classes
// May wish to (optionally) expose internals though the facade
// May allow users to 'escalate' to use more complex APIs if they need to
//
//
stuct window
{
   int width, height;
   GLFWwindow * handle = nullptr;

   std::shared_ptr<TextRenderer> text_renderer;
   std::vector<std::shared_ptr<IBuffer> > buffer;
   std::vector<std::shard_ptr<Viewport>> viewports;

   static void ResizeFunction(GLFWindow*, int, int);

   Window(std::string title, int width, int height);

   void DrawEverything();

   void show();

   static void KeyFunction(GLFWindow* handle, int key, int scancode);

   std::pair<int,int> size() const;

   ~window();

};


class IBuffer
{
  public:
    virtual ~IBuffer(){}

    virtual Size get_size() const = 0;

    virtual char operator()(uint32_t x, uint32_t y) = 0;

    virtual void add_string(const std::string& s) = 0;

};


class TextBuffer: public IBuffer
{
  //if the buffer is full, it will become circular
  boost::circular_buffer<std::string> lines;

  const std::string line_break = "\n";
  uint32_t width, height;

  public:
  TextBuffer(uint32_t width, uint32_t height);
  Size get_size() const override;
  std::string to_string();

  char operator()(uint32_t x, uint32_t y) override;
  void add_string (std::string & s ) override;


};

char TextBuffer::operator()(uint32_t x , uint32_t y);
{
   if( y+1 > lines.size())
     return 0;
   return x+1 > lines[y].size() ? 0 :linex[y][x]
}


std::string TextBuffer::to_string()
{
  std::ostringstream oss;
  for(auto & line: lines)
  {
    oss<< line <<line_break;
  }
  return oss.str();
}

class Viewport
{
  protected:
    std::shared_ptr<IBuffer> buffer;
    Point buffer_location;
    Point screen_location;
    Size size;
  public:
    Viewport(const std::shared_ptr<IBuffer> & buffer, boost::optional<Size> size=boost::none,
        boost::optional<Point> buffer_location = boost::none,
        boost::optional<Point> screen_location = boost::none)
      :buffer(buffer)
    {
      this->size = size.value_or(buffer->get_size());
      this->buffer_location = buffer_location.value_or(Point{});
      this->screen_location = screen_location.value_or(Point{});
    }

    char operator()(int x, int y) const
    {
      if( (x >= screen_location.x) && x <(screen_location.x + size.width) &&
          (y>= screen_location.y) && y <(screen_location.y + size.height))
      {
        return (*buffer)(x-screen_location.x, y-screen_location.y); 
      }
      return 0;
    
    }

};


int main()
{
 window window("Test", 1280,720);

 auto buffer = make_shared<TextBuffer>(40,40);

 buffer->add_string("One");
 buffer->add_string("One");
 buffer->add_string("One");
 buffer->add_string("One");
 buffer->add_string("One");
 buffer->add_string("One");
 window.buffers.push_back(buffer);

 auto viewport = make_shared<Viewport>(buffer);
 window.viewport.emplace_back(viewport);

 auto viewport2 = make_shared<Viewport>(buffer, Size{40,40}, Point{}, Point{45, 0});
 window.viewport.emplace_back(viewport2);
 
 auto viewport3 = make_shared<Viewport>(buffer, Size(40,40}, Point{}, Point{90, 0});
 window.viewport.emplace_back(viewport3);

 window Show();
}

//refine the above example by using the Facade pattern
//
//

class Console
{
public:
  std::vector<std::shared_ptr<Window>> windows;

  static Console& instance()
  {
    static Console console;
    return console;
  }

  shared_ptr<Window> multicolumn(const std::string &title, int columnCount,int columnWidth int charsHigh)
  {
    auto w = make_shared<Window>(title, columnCount*columnWidth* charwidth, charsHigh * charHeight);
    for(int c =0; c<columnCount; ++c)
    {
      auto buffer = make_shared<TextBuffer>(columnWidth, charsHigh);
      w->buffers.push_back(buffer);
      auto viewport = make_shared<Viewport>(buffer, buffer->get_size(), Point{}, Point{columnWidth*c, 0});
      w->viewports.push_back(viewport
    } 
    return w;
  
  }
  shared_ptr<Window> single(const std::string &title, int charsWide, int charsHight )
  {
    auto w = make_shared<Window>(title, charsWide* charwidth, charsHigh * charHeight);

    auto buffer = make_shared<TextBuffier>(charsWide, charsHigh);

    w->buffers.push_back(buffer);
    auto viewport = make_shared<Viewport>(buffer);
    w->viewports.push_back(viewport);
    windows.push_back(w);
    return w;
  }

 static Console& instance()
  private:
  const int charWidth = 10, charHeight = 14;
  Console(){}
  Console(Console const &) = delete;
  void operator=( Console const & )= delete;
};

int main()
{
  auto window = Console::instance().single("Test", 50, 30);
  window->Show();

  auto window2 = Console::instance().multicolumn("text", 2, 40, 40);
  for(size_t i=0; i< 40; i++)
  {
    window->buffers[1]->add_string("This is line" + boost::lexical_cast<string>(i)); 
  }

  window->Show();
}

