#include <iostream>
#include<string>
#include<vector>
#include<functional>
#include "MascaChirurgicala.h"
#include "MascaPolicarbonat.h"
#include "IO.h"
#include "Masca.h"


using namespace std;

class Menu
        {

        private:
                    static Menu* ptr;
                    vector<pair< string, function<void()>>> op;
                    Menu();
                    Menu(const Menu&) = delete;
                    Menu& operator=(const Menu&) = delete;
        public:
            void run();
            static Menu* get_ptr();
            static void delete_ptr();
        };
Menu* Menu::ptr = nullptr;

Menu::Menu()
{
    op.push_back(make_pair("Demo",[&]()
    {
        MascaChirurgicala mc1, mc2("ffp2", "verde brotăcel", 55), mc3(mc1), mc4, mc5;
        mc4 = mc2;
        cin >> mc5;
        cout << mc1 << mc2;
        MascaPolicarbonat* mp1 = new MascaPolicarbonat(), * mp2=new MascaPolicarbonat();
        MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");
        cin >> *mp1 >> *mp2;
        cout << *mp3;


    }));
    op.push_back(make_pair("Adauga dezinfectant", [&]()
    {

    }));
}
void Menu::run()
{
    bool running = true;

    while (running)
    {
        try
        {
            int operatie;

            cout << "Alege operatia" << endl;
            for (int i = 0; i < op.size(); i++)
                cout << i << ") " << op[i].first << endl;
            cout << op.size() << ") Inchidere" << endl;

            cin >> operatie;
            if (operatie < 0 || operatie > op.size())
                throw runtime_error("Optiune invalida");

            if (operatie == op.size())
            {
                running = false;
                continue;
            }

            op[operatie].second();
        }
        catch(const exception& e)
        {
            cout << "Am intampinat o problema: " << e.what() << endl;
        }

    }
}
Menu* Menu::get_ptr() {
    if(!ptr)
        ptr = new Menu();
    return ptr;
}

void Menu::delete_ptr()
{
    delete ptr;
    ptr = nullptr;
}


int main() {
    Menu::get_ptr()->run();
    Menu::delete_ptr();
}
