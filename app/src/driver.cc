

// int main(int argc, char **argv)
// {
// Parser parser;
// parser.parse();

// }
#include "Scanner.ih"
using namespace std;

int main()
{
    Scanner scanner; // define a Scanner object

    while (int token = scanner.lex()) // get all tokens
    {
        string const &text = scanner.matched();
        switch (token)
        {
        case Parser::ADD:
            cout << "识别符号ADD" << text << endl;
            break;
        default:
            
            break;
        }
    }
}