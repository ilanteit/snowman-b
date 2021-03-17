#include <iostream>
#include <string>
#include <stdexcept>
#include "snowman.hpp"
const int TEN = 10;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int MAXNUMBER =44444444;
const int MINNUMBER=11111111;
using namespace std;

const array<string, FIVE> H = {"", "_===_\n", " ___ \n .....\n", "  _  \n /_\\ \n", " ___ \n(_*_)\n"};
const array<string, FIVE> N = {"", ",", ".", "_", ""};
const array<string, FIVE> L = {"", "(.", "(o", "(O", "(-"};
const array<string, FIVE> R = {"", ".)", "o)", "O)", "-)"};
const array<string, FIVE> X = {"", "<", "\\", "/", ""};
const array<string, FIVE> Y = {"", ">\n", "\\\n", "/\n", ""};
const array<string, FIVE> T = {"", "( : )", "(] [)", "(> <)", "(   )"};
const array<string, FIVE> B = {"", "( : )", "(\" \")", "(___)", "(   )"};
std::string realSnowMan;

namespace ariel
{
    bool correctInput(int x)
    {

        if (x < MINNUMBER || x > MAXNUMBER)
        {
            return false;
        }
        int temp = x;
        int tempDigit = x % TEN;
        while (temp > 0)
        {
            if (tempDigit > FOUR || tempDigit < ONE)
            {

                return false;
            }

            temp = temp / TEN;
            tempDigit = temp % TEN;
        }
        return true;
    }

    string snowman(int num)
    {
        if (!correctInput(num))
        {
            string error = "Invalid code '" + std::to_string(num) + "'";
            throw std::invalid_argument(error);
        }
        realSnowMan = "";
        int temp = num;
        int h=ZERO; int n=ZERO; int l=ZERO; int r=ZERO;int x=ZERO;int y=ZERO;int b=ZERO;int  t = ZERO;
        int leftUp=0;int leftDown=0;int rightUp=0;int rightDown = 0;

        array<int, EIGHT> SingleDigit = {0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = ZERO; i < EIGHT; i++)
        {
            SingleDigit.at(i) = temp % TEN;
            temp = temp / TEN;
        }

        printHead(H.at(SingleDigit.at(SEVEN)));

        if (SingleDigit.at(THREE) == TWO)
        {
            leftUp = ONE;
        }

        if (SingleDigit.at(TWO) == TWO)
        {
            rightUp = ONE;
        }
        if (SingleDigit.at(THREE) == THREE)
        {
            leftDown = ONE;
        }

        if (SingleDigit.at(TWO) == THREE)
        {
            rightDown = ONE;
        }
        printFace(N.at(SingleDigit.at(SIX)), L.at(SingleDigit.at(FIVE)), R.at(SingleDigit.at(FOUR)), leftUp, rightUp);
        printTorso(SingleDigit.at(THREE), SingleDigit.at(TWO), T.at(SingleDigit.at(ONE)));
        printBase(B.at(SingleDigit.at(ZERO)), leftDown, rightDown);

        return realSnowMan;
    }
    void enter()
    {
        realSnowMan += "\n";
    }

    void printHead(const std::string &h)
    {
        realSnowMan += h;
    }
    void printFace(const std::string &n, const std::string &l, const std::string &r, int leftUp, int rightUp)
    {
        if (leftUp == ONE)
        {
            realSnowMan += "\\";
        }
        realSnowMan += l + n + r;
        if (rightUp == ONE)
        {
            realSnowMan += "/";
        }
        enter();
    }
    void printTorso(int x, int y, const std::string &t)
    {
        if (x == 1)
        {
            realSnowMan += "<";
        }
        realSnowMan += t;
        if (y == 1)
        {
            realSnowMan += ">";
        }
        enter();
    }
    void printBase(const std::string &b, int leftDown, int rightDown)
    {
        if (leftDown == ONE)
        {
            realSnowMan += "/";
        }
        realSnowMan += b;
        if (rightDown == ONE)
        {
            realSnowMan += "\\\n";
        }
        enter();
    }
}