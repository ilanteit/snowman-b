#include <string>
#include <iostream>
#include <array>



namespace ariel
{
bool correctInput(int x);
std::string snowman(int num);
void printHead(const std::string &h);
void printFace(const std::string &n,const std::string &l,const std::string &r,int leftUp,int rightUp);
void printTorso(int x,int y, const std::string &t);
void printBase(const std::string &b, int leftDown, int rightDown);



}