
#include "connection.hpp"

void Connection::command_handler()
{
    /*std::cout << programm_index << std::endl;

    create_tablo_information();*/

    bool error_key = false;

    std::string error_line;

    if ( button_hash % 10 == 1 )
    {
        // command 'p'to registers

        mem.storeRegister( button_hash / 10);

        num_button_flag = false;

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 2 )
    {
        // command 'f' to x from registers

        mem.loadRegister( button_hash / 10);

        num_button_flag = false;

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 3 )
    {
        switch ( button_hash / 10)
        {
            case 0:
                mem.cosinus(); // e^ix
                break;

            case 1:
                mem.ln(); // ln
                break;

            case 2:
                mem.pi(); // pi
                break;

            case 3:
                 mem.expPower(); // e^x
                break;

            /*
            
            case 4:
                create_tablo_information();
                break;

            case 5:
                create_tablo_information();
                break;

            case 6:
                create_tablo_information();
                break;

            case 7:
                create_tablo_information();
                break;
            
            */

            case 8:
                mem.cosinus(); //create_tablo_information(); } // cos
                break;

            case 9:
                mem.sinus(); // sin
                break;

            /*
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }
            
            */
        };

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 4 )
    {
        //mem.roundStack[0] = mem.roundStack[0] * 10 + button_hash / 10;

        //screen_data.screen_tablo = mem.roundStack[0];

        num_button_flag = true;

        mem.storeDigit( button_hash / 10, comma_button_flag);

        //comma_button_flag

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 5 )
    {
        num_button_flag = false;

        switch ( button_hash / 10)
        {
            /*
            
            case 0:
                create_tablo_information();
                break;

            case 1:
                create_tablo_information();
                break;

            case 2:
                create_tablo_information();
                break;

            case 3:
                 create_tablo_information();
                break;
            
            */

            case 4:
            {
                try { mem.reciprocal(); }
                catch( ... ) { error_key = true; error_line = "ERROR - division by 0";}//screen_data.ball[0] = "ERROR"; std::cout << screen_data.ball[0] << std::endl; } //create_tablo_information();// 1/x

                break;
            }
        
            case 5:
            {
                mem.square(); //create_tablo_information();// x^2
                
                //create_tablo_information();

                break;
            }
            case 6:
            {
                //create_tablo_information();// sqrt
                mem.squareRoot();
                
                //create_tablo_information();
                
                break;
            }
            /*
            
            case 7:
                create_tablo_information();
                break;

            case 8:
                create_tablo_information();
                break;

            case 9:
                create_tablo_information();
                break;
            
            */


            /*
            
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }

            */
        };
    }
    else if ( button_hash % 10 == 6)
    {
        num_button_flag = false;

        switch ( button_hash / 10)
        {
            case 0:
                mem.storeRegister(0); // from x to y
                break;

            case 1:
                mem.xyChange(); // change x and y
                break;

            case 2:
                mem.dot();
                break;

            case 3:
                 mem.divide();
                break;

            case 4:
                // comma
                comma_button_flag = true;
                break;

            case 5:
                mem.opposite();
                break;

            /*
            
            case 6:
                create_tablo_information();// BH
                break;

            case 7:
                create_tablo_information();// RESET - CX
                break;
            */

            case 8:
                mem.minus();
                break;

            case 9:
                mem.plus();
                break;

            /*
            
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }

            */
        };
    
        //create_tablo_information();
    }

    create_tablo_information(error_key, error_line);

}

void Connection::add_program_handler()
{
    program_mem.add(button_hash);
}

void Connection::create_tablo_information(bool str_here, std::string error_line)
{
    //mem.roundStack[0];
    //mem.registers[0];

    //std::cout << std::to_string( mem.roundStack[0]) << std::endl;

    //screen_data.screen_tablo = to_string( mem.roundStack[0]);

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        screen_data.ball[ind] = std::to_string( mem.roundStack[ind]);

        screen_data.registers[ind] = std::to_string( mem.registers[ind]);
    }

    if ( str_here == true )
        screen_data.ball[0] = error_line;

    for ( size_t ind = 0; ind < 36; ind++ )
    {        
            screen_data.program_memory[ind] = std::to_string( program_mem.program_memory[ind]);
    }



    std::cout << "--------registers-------- \n YYY:" << std::endl;

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        std::cout << screen_data.registers[ind] << std::endl;

    }

    std::cout << "--------ball-------- \n XXX:" << std::endl;

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        std::cout << screen_data.ball[ind] << std::endl;

    }

    std::cout << "--------program--------" << std::endl;
    
    for ( size_t ind = 0; ind < 36; ind++ )
    {
        if (ind % 7 < 6)
            std::cout << screen_data.program_memory[ind] << " ";
        else
            std::cout << screen_data.program_memory[ind] << std::endl; //screen_data.program_memory[ind] << std::endl;

    }

    std::cout << std::endl;
}

void Connection::get_button_num(int button_index)
{
    if (button_index == 'P'
        ||
        button_index == 'F'
       )
    {
        //button_hash = button_index;

        if ( button_index == 'P' )
            button_hash = 1;
        else
            button_hash = 2;

        mode_pressed = true;
    }
    else
    {
        // handler of P and F mode
        if ( mode_pressed == true )
        {

            if ( button_index % 10 == 4 )
            {
                if ( button_hash == 1)
                    button_hash = button_index - 3;
                else if ( button_hash == 2 )
                    button_hash = button_index - 2;
            }
            else if ( button_index % 10 == 6 )
            {
                if ( button_index == 76)
                {
                    button_hash = 76;
                }
                else if ( button_hash == 1)
                    button_hash = button_index - 3;
                else if ( button_hash == 2 )
                    button_hash = button_index - 1;
                // ERROR HERE WHAT WE NEED TO DO
                //else if ( button_index == 76)

            }
            else if ( button_index % 10 == 8)
            {
                if ( button_hash == 1)
                    button_hash += button_index;
                else if ( button_hash == 2 )
                    button_hash = button_index - 1;
            }
            /*else if ( butto_index == "РП" )
            {
                mode_enter_progarm = true;
            }*/
            
            // reset mode pressed button

            mode_pressed = false;
        }
        else
        {
            button_hash = button_index;
        }

        if ( mode_enter_progarm == true )
        {
            add_program_handler();
        }
        else
            command_handler();
    }
}

int main()
{
    Connection x;

    x.get_button_num('F');
    x.get_button_num(48);

    x.get_button_num('P');
    x.get_button_num(48);

    x.get_button_num('F');
    x.get_button_num(46);

    x.get_button_num('P');
    x.get_button_num(46);

    x.get_button_num(76);

    x.get_button_num(34);
    x.get_button_num(64);
    x.get_button_num(46);
    x.get_button_num(34);

    x.get_button_num('P');
    x.get_button_num(86);

    x.get_button_num(16);

    //std::cout << "tablo information " << x.screen_data.screen_tablo << std::endl;

    //x.mem.Dump();

    return 0;
}
