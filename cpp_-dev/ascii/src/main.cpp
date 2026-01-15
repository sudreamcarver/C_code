#include <iostream>
#include <string>

int
main ()
{
    // 错误示范：如果不使用 R"()"，你需要疯狂加反斜杠
    // std::string badSword = "  / \\ ";  // 还要考虑引号嵌套，很烦

    // 正确示范：R"( ... )" 括号里的东西，所见即所得
    std::string sword = R"(
      O
     /|\
     / \
    )";

    std::string dragon = R"(
        ,     \    /      ,
       / \    )\__/(     / \
      /   \  (_\  /_)   /   \
 ____/_____\__\@  @/___/_____\____
|             |\../|              |
|              \VV/               |
|_________________________________|
    )";

    std::cout << "--- Hero ---" << std::endl;
    std::cout << sword << std::endl;

    std::cout << "--- Boss ---" << std::endl;
    std::cout << dragon << std::endl;

    return 0;
}
