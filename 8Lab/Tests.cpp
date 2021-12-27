#include "gtest/gtest.h"
#include "Calc.h"

Stack<int> stack;
Calc* ex = new Calc();
std::string c;

TEST(Simple, Sum){
    c = "57+45";
    ASSERT_EQ(ex->calculate(c), 102);
}

TEST(Simple, InfMin){
    c = "-45";
    ASSERT_EQ(ex->calculate(c), -45);
}

TEST(Simple, Min){
    c = "57-45";
    ASSERT_EQ(ex->calculate(c), 12);
}

TEST(Simple, Div){
    c = "57/45";
    ASSERT_EQ(ex->calculate(c), (double) 57/45);
}

TEST(Simple, Mult){
    c = "57*45";
    ASSERT_EQ(ex->calculate(c), 57*45);
}

TEST(SimpleDouble, Sum){
    c = "57.45907+45.9576365";
    ASSERT_EQ(ex->calculate(c), 103.4167065);
}

TEST(SimpleDouble, Min){
    c = "57.45907-45.9576365";
    ASSERT_EQ(ex->calculate(c), (double) 57.45907-45.9576365);
}

TEST(SimpleDouble, Div){
    c = "57.45907/45.9576365";
    ASSERT_EQ(ex->calculate(c), (double) 57.45907/45.9576365);
}

TEST(SimpleDouble, Mult){
    c = "57.45907*45.9576365";
    ASSERT_EQ(ex->calculate(c),(double) 57.45907*45.9576365);
}

TEST(DoubleWithComma, Sum){
    c = "57,45907+45,9576365";
    ASSERT_EQ(ex->calculate(c), 103.4167065);
}

TEST(Bigger, Sum) {
    c = "57*45-(25+72)";
    ASSERT_EQ(ex->calculate(c), 2468);
}
TEST(Bigger, Double){
    c = "57*45-5*(25+72.34)";
    ASSERT_EQ(ex->calculate(c), 2078.3);
}

TEST(Bigger, DoubleMin){
    c = "57*45--(25+72.34)";
    ASSERT_EQ(ex->calculate(c), 2662.34);
}

TEST(Complex, 1){
    c = "57*45--5*(25+72.34)--57/24";
    ASSERT_EQ(ex->calculate(c), 3054.075);
}

TEST(Break, DoubleMult){
    c = "57**45-(25+72.34)";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(Break, DoubleDiv){
    c = "57//45-(25+72.34)";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(Break, DoubleAdd){
    c = "57*45-(25++72.34)";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(Break, InvalidChar){
    c = "57*45-(25++72.&34)";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(Break, NoEndingC ){
    c = "57*45-(25++72.34";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(Break, WrongStrting){
    c = ")57*45-25++72.34";
    ASSERT_ANY_THROW(ex->calculate(c));
}

TEST(First, Brakets){
    c = "(57*45-25)*5";
    ASSERT_EQ(ex->calculate(c), 12700);
}

TEST(First, Minus){
    c = "-(57*45-25)*5";
    ASSERT_EQ(ex->calculate(c), -12700);
}

TEST(Stack, Push){
    stack << 5;
    stack << 20;
    ASSERT_EQ(20, stack.top());
}

TEST(Stack, Pop){
    int i = 0;
    stack >> i;
    ASSERT_EQ(stack.top(), 5);
}

TEST(Stack, ElementByNum){
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    ASSERT_EQ(stack[1], 5);
}

TEST(Stack, Asignement){
    Stack<int> temp;
    temp << 6543;
    temp = stack;
    ASSERT_EQ(stack.getSize(), temp.getSize());
    for (int i = 0; i < stack.getSize(); ++i) {
        ASSERT_EQ(temp[i], stack[i]);
    }
}


