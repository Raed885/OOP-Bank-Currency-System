#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"
using namespace std;    


int main()
{
	while (true) { //This loop will keep showing the login screen until the user successfully logs in or chooses to exit.

        if (!clsLoginScreen::ShowLoginScreen()) { // the ! checks if 
            break;
        }
    } 

    

        return 0;
    }
