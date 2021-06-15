#include "FileWithUsers.h"



 void FileWithUsers::addUsersToFile(User user)
 {
     if(isFileEmpty()==true)
     {
      CMarkup xml;
      xml.AddElem("USERS");
     }

    CMarkup xml;
    xml.Load("FileWithUsers.xml");
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
    xml.Save("FileWithUsers.xml");
 }

 bool FileWithUsers::isFileEmpty()
{


    bool isEmpty = true;
    CMarkup xml;
    xml.Load("FileWithUsers.xml");
    xml.FindElem();
    xml.IntoElem();
    string data =xml.GetData();
    if (data.empty())
    {
       isEmpty = true;
    }
    else isEmpty =false;


    return isEmpty;

 }

vector<User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup xml;
    xml.Load("FileWithUsers.xml");
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
