#include "shapesdeal.h"

ShapesDeal ::ShapesDeal()
{

}

ShapesDeal ::ShapesDeal(string file)
{
    this ->m_file = file;
}

ShapesDeal::~ShapesDeal()
{

}

void ShapesDeal::WindowShow()
{
    sf::ContextSettings settings;   //Antialiased shapes
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(1000, 600), "GraficSFML",Style::Default,settings);
    window.setFramerateLimit(60);

    Menu();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Z)
                {
                    system ("cls");
                    Menu();
                    AddFigure();
                }
                if(event.key.code == Keyboard::Tab)     //change the active object
                {
                    if(active_object == objects.size()-1)
                        active_object = 0;
                    else
                        ++active_object;
                }
                if(event.key.code == Keyboard::C)
                {
                  if(counter > 4)
                     counter = 0;

                  objects[active_object] -> Change_Collor(counter);
                   ++counter;
                }
                if(event.key.code == Keyboard::U)
                {
                   objects[active_object] -> set_Visible();
                }
                if(event.key.code == Keyboard::T)
                {
                   objects[active_object] -> set_Trace();
                }
                if(event.key.code == Keyboard::Num1)
                {
                    system ("cls");
                    Menu();
                    if(objects.empty())
                    {
                      cout<<"No shapes created!";
                       break;
                    }
                    else
                        objects.clear();
                }
                if(event.key.code == Keyboard::R)
                {
                   system ("cls");
                   Menu();
                   Reset();
                }
                if(event.key.code == Keyboard::V)
                {
                  if(!objects.empty())
                  {  objects[active_object] -> Set_M_Trajectory();

                   if(!objects[active_object] -> Get_M_Trajectory())
                   {
                       system ("cls");
                       Menu();
                       cout<<"Remembering the trajectory - ON"<<endl;
                      position = objects[active_object] -> getPosition();
                   }

                   if(objects[active_object] -> Get_M_Trajectory())
                   {
                      cout<<"Remembering the trajectory - OFF"<<endl;
                      objects[active_object] -> setPosition(position.x,position.y);
                   }
                  }
                }
                if(event.key.code == Keyboard::M)
                {
                   system ("cls");
                   Menu();
                   Agregation();
                }
                if(event.key.code == Keyboard::Num3)
                {
                   Save();
                }
                if(event.key.code == Keyboard::Num2)
                {
                   Load();
                }
            }
        }
    if(objects.size())
     {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            objects[active_object] ->scale(0.9f,0.9f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            objects[active_object] ->scale(1.1f,1.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            objects[active_object] ->move(-10.f,0.f);

            if(!objects[active_object] -> Get_M_Trajectory())
            {
                objects[active_object] -> Write_Trajectory("left");
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            objects[active_object] ->move(0.f,-10.f);

            if(!objects[active_object] -> Get_M_Trajectory())
            {
                objects[active_object] -> Write_Trajectory("up");

            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            objects[active_object] ->move(0.f,10.f);

            if(!objects[active_object] -> Get_M_Trajectory())
            {
                objects[active_object] -> Write_Trajectory("down");
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            objects[active_object] ->move(10.f,0.f);

            if(!objects[active_object] -> Get_M_Trajectory())
            {
                objects[active_object] -> Write_Trajectory("right");
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            if((rotate - rotation_step) < 0.f)
            {
                objects[active_object]->setRotation(rotate = 360.f + (rotate - rotation_step));
            }
            else
            {
                objects[active_object]->setRotation(rotate -= rotation_step);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            if((rotate + rotation_step) > 360.f)
            {
                objects[active_object]->setRotation(rotate = 360.f - (rotate - rotation_step));
            }
            else
            {
                objects[active_object]->setRotation(rotate += rotation_step);
            }
        }
     }

     if(objects.empty())
        window.clear(Color(188,220,252));
     else if(objects[active_object] -> get_Trace())
        window.clear(Color(188,220,252));

     if(!objects.empty())
     {
        for(auto &obj:objects)
        {
          if(obj -> Size_Vector())
        {
            if(obj -> Get_M_Trajectory())
         {
             constexpr float speed = 10.f;

             if(obj -> Output_Trajectory(index) == "left")
             {
                position.x -= speed;
                obj ->setPosition(position);
             }

             if(obj -> Output_Trajectory(index) == "up")
             {
                position.y -= speed;
                obj ->setPosition(position);
             }

             if(obj -> Output_Trajectory(index) == "down")
             {
                position.y += speed;
                obj ->setPosition(position);
             }

             if(obj -> Output_Trajectory(index) == "right")
              {
                position.x += speed;
                obj ->setPosition(position);
              }

             if(index == obj -> Size_Vector()-1)
                {
                 obj ->Delet_Trajectory();
                 index = 0;
                }
             else
                 index++;
         }
        }
          if(obj -> get_Visible())
            window.draw(*obj);
        }
     }
        window.display();
   }
}


void ShapesDeal ::Menu()
{
    cout<<"       HOTKEYS              "<<endl;
    cout<<"\n Add Figure - Z "<<endl;
    cout<<" Move the object - A,W,S,D "<<endl;
    cout<<" Rotate figure - Q,E "<<endl;
    cout<<" Moving with|no trace - T"<<endl;
    cout<<" Restore object - R"<<endl;
    cout<<" Change color - C "<<endl;
    cout<<" In/visable - U "<<endl;
    cout<<" Scale - X,Y "<<endl;
    cout<<" Swith figure - Tab "<<endl;
    cout<<" Make an aggregate - M "<<endl;
    cout<<" Remember the trajectory - V"<<endl;
    cout<<"\n Delete all objects - 1"<<endl;
    cout<<" Load configuration - 2"<<endl;
    cout<<" Save configuration - 3"<<endl;
    cout<<"____________________________"<<endl;
}

void ShapesDeal::AddFigure()
{  
    cout<<"\n What figure you want to add?"<<endl;
    cout<<"\n 1 -> Circle"<<endl;
    cout<<" 2 -> Square"<<endl;
    cout<<" 3 -> Triangle"<<endl;
    cout<<" 4 -> Line"<<endl;
    cout<<" 5 -> Star"<<endl;

    int number;
    string name_f;
    cout<<"\n Number: ";cin>>number;
    cout<<" Enter the name of figure: ";cin>>name_f;

    switch(number)
    {
    case 1:
            objects.push_back(new Circle());
        break;
    case 2:
            objects.push_back(new Square());
        break;
    case 3:
            objects.push_back(new Triangle());
        break;
    case 4:
            objects.push_back(new Line());
        break;
    case 5:
            objects.push_back(new Star());
        break;
    }

    objects[objects.size()-1] -> Set_Name(name_f);

}

void ShapesDeal :: Reset()
{
    if(objects.empty())
    {
      cout<<"No shapes created!"<<endl;
      return;
    }

  string copy_name;
  copy_name = objects[active_object] -> Get_Name();

  int type = static_cast<int>(objects[active_object] -> get_type());

  auto iter = objects.begin();
  objects.erase(iter+active_object);

  switch(type)
  {
    case 0:
           objects.push_back(new Circle());
           break;
    case 1:
           objects.push_back(new Triangle());
           break;
    case 2:
           objects.push_back(new Square());
           break;
    case 3:
           objects.push_back(new Star());
           break;
    case 4:
           objects.push_back(new Line());
           break;
  }

  active_object = objects.size() - 1;
  objects[active_object] -> Set_Name(copy_name);

}

void ShapesDeal :: Agregation()
{
    if(objects.size() > 1)
    {
    cout<<" Enter the name of figures you want aggregate"<<endl;
    cout<<"\n The names of shapes you have :"<<endl;

    for(auto &obj:objects)
    {
        string names;
        names = obj -> Get_Name();
        cout<<"     "<<names<<"      "<<endl;
    }

    string name_1;
    cout<<"\n First figure : "; cin>>name_1;
    string name_2;
    cout<<" Second figure : "; cin>>name_2;
    string name_ag;
    cout<<"\n Enter the name of aggragate : "; cin>> name_ag;

    size_t temp_i = 0;
    size_t temp_j;

    for(size_t i = 0; i < objects.size(); i++)
    {
        for(size_t j = 0; j < objects.size(); j++)
        {
            if(objects[i] -> Get_Name() == name_1)
                temp_i = i;
            if(objects[j] -> Get_Name() == name_2)
                temp_j = j;
        }
    }

    objects.push_back(new Agregate(objects[temp_i] -> Copy_Figure(),objects[temp_j] -> Copy_Figure()));
    objects[objects.size()-1] ->Set_Name(name_ag);

    auto iter = objects.begin();
    objects.erase(iter+temp_j);
    objects.erase(iter+temp_i);
   }
    else
       {
        cout<<" You have less then 2 figures"<<endl;
       }
}

void ShapesDeal :: Save()
{
    std::ofstream fout;
    fout.open(m_file, ifstream::app);
    fout.unsetf(ios::floatfield);
    fout.precision(10);

    if(!fout.is_open())
    {
        cout<<" Error!Try again.\n";
        return;
    }
    else
    {
        for(size_t i = 0; i < objects.size();++i)
        {
            fout<<"\n  "<<static_cast<int>(objects[i] -> get_type())<<"    "<<objects[i] -> Get_Name()
            <<"    "<< objects[i] ->getPosition().x<<"    "<<objects[i] ->getPosition().y
            <<"    "<< objects[i] ->getOrigin().x<<"    "<< objects[i] ->getOrigin().y
            <<"    "<< objects[i] ->getScale().x<<"    "<< objects[i] ->getScale().y
            <<"    "<< objects[i] ->getRotation()<<"    "<< objects[i]-> Get_Collor()<<"     "<< objects[i] ->get_Trace()
            <<"    "<< objects[i] ->get_Visible()<<"    "<< objects[i] ->Get_M_Trajectory();
        }
    }
    fout.close();

    system("cls");
    cout<<"\n Configuration successfully saved!"<<endl;
}

void ShapesDeal :: Load()
{
    ifstream fin;
    fin.open(m_file);

    objects.clear();

    string name;
    size_t i = 0;
    int type;
    int collor;
    float pos_x;
    float pos_y;
    float origin_x;
    float origin_y;
    float scale_x;
    float scale_y;
    float rotation;
    bool visible;
    bool trace;
    bool traject;

    while(!fin.eof())
    {
        fin>>type;
        fin>>name;
        fin>>pos_x;
        fin>>pos_y;
        fin>>origin_x;
        fin>>origin_y;
        fin>>scale_x;
        fin>>scale_y;
        fin>>rotation;
        fin>>collor;
        fin>>trace;
        fin>>visible;
        fin>>traject;

        switch(type)
        {
          case 0:
                 objects.push_back(new Circle());
                 break;
          case 1:
                 objects.push_back(new Triangle());
                 break;
          case 2:
                 objects.push_back(new Square());
                 break;
          case 3:
                 objects.push_back(new Star());
                 break;
          case 4:
                 objects.push_back(new Line());
                 break;
        }

        objects[i] -> Set_Name(name);
        objects[i] -> setPosition(pos_x,pos_y);
        objects[i] -> setOrigin(origin_x,origin_y);
        objects[i] -> setScale(scale_x,scale_y);
        objects[i] -> setRotation(rotation);
        objects[i] -> Change_Collor(collor);

        if(!trace)
            objects[i] -> set_Trace();
        if(!visible)
            objects[i] -> set_Visible();
        if(!traject)
            objects[i] -> Set_M_Trajectory();
        ++i;

    }

    active_object = objects.size() - 1;
    fin.close();

    cout<<"\n Configuration successfully load!"<<endl;
}
