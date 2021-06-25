#include "FileWithUsers.h"



 void FileWithUsers::addUsersToFile(User user)
 {
     if(isFileEmpty()==true)
     {
      CMarkup xml;
      xml.AddElem("USERS");
      xml.Save("users.xml");

     }

    CMarkup xml;
    xml.Load("users.xml");

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User");
    xml.IntoElem();
    xml.AddElem( "ID" ,user.getId());
    xml.AddElem( "NAME",user.getName());
    xml.AddElem( "SURNAME" ,user.getSurname());
    xml.AddElem( "LOGIN" ,user.getLogin());
    xml.AddElem( "PASSWORD",user.getPassword());
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("users.xml");



 }

 bool FileWithUsers::isFileEmpty()
{


    bool isEmpty = true;
    CMarkup xml;
    xml.Load("users.xml");
   if (xml.FindElem() == true)
   {
       isEmpty = false;
   }
   else isEmpty = true;

    return isEmpty;

 }

vector<User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup xml;
    xml.Load("users.xml");
xml.ResetPos();
xml.FindElem();
xml.IntoElem();
while (xml.FindElem("User"))
       {
           xml.IntoElem();
           xml.FindElem("ID");
           int loadedId = atoi(MCD_2PCSZ(xml.GetData()));
       //    xml.ResetMainPos();

           xml.FindElem("NAME");
           string loadedName = xml.GetData();

           xml.FindElem("SURNAME");
           string loadedSurname = xml.GetData();

           xml.FindElem("LOGIN");
           string loadedLogin = xml.GetData();

           xml.FindElem("PASSWORD");
           string loadedPassword = xml.GetData();

           xml.OutOfElem();

           user.setId(loadedId);
           user.setName(loadedName);
           user.setSurname(loadedSurname);
           user.setLogin(loadedLogin);
           user.setPassword(loadedPassword);

           users.push_back(user);

       }
       return users;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;
    xml.AddElem("USERS");
    xml.Save("users.xml");
    for (int i=0; i<users.size(); i++)
    {
    CMarkup xml;
    xml.Load("users.xml");
    xml.FindElem();
    xml.IntoElem();
    xml.IntoElem();
    xml.AddElem( "User");
    xml.IntoElem();
    xml.AddElem( "ID" ,users[i].getId());
    xml.AddElem( "NAME",users[i].getName());
    xml.AddElem( "SURNAME" ,users[i].getSurname());
    xml.AddElem( "LOGIN" ,users[i].getLogin());
    xml.AddElem( "PASSWORD",users[i].getPassword());
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("users.xml");
    }
}
