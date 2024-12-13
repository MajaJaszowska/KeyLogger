#include "KeyRepresentation.h"
#include <Windows.h>
#include <sstream>

bool ShiftPressed_LAST = false;

std::string GetKeyRepresentation(const int key_press_number) {

    bool ShiftPressed_NOW = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;

    // shift sam
    if (ShiftPressed_NOW && !ShiftPressed_LAST) {
        ShiftPressed_LAST = true;
        return "[SHIFT]";
    }

    // shift zwolniony
    if (!ShiftPressed_NOW && ShiftPressed_LAST) {
        ShiftPressed_LAST = false;
    }

    std::ostringstream result;

    if (key_press_number >= 'a' && key_press_number <= 'z') {
        if (ShiftPressed_NOW) {
            result << char(key_press_number - 'a' + 'A');
        } else {
            result << char(key_press_number);
        }
    } else if (key_press_number >= 'A' && key_press_number <= 'Z') {
        if (ShiftPressed_NOW) {
            result << char(key_press_number);
        } else {
            result << char(key_press_number + 'a' - 'A');
        }
    }

    if (ShiftPressed_NOW) {

        switch (key_press_number) {

        case '1': result << '!'; break;
        case '2': result << '@'; break;
        case '3': result << '#'; break;
        case '4': result << '$'; break;
        case '5': result << '%'; break;
        case '6': result << '^'; break;
        case '7': result << '&'; break;
        case '8': result << '*'; break;
        case '9': result << '('; break;
        case '0': result << ')'; break;


        case VK_OEM_MINUS: result << '_'; break;
        case VK_OEM_PLUS: result << '+'; break;
        case VK_OEM_4: result << '{'; break;
        case VK_OEM_6: result << '}'; break;
        case VK_OEM_1: result << ':'; break;
        case VK_OEM_7: result << '"'; break;
        case VK_OEM_COMMA: result << '<'; break;
        case VK_OEM_PERIOD: result << '>'; break;
        case VK_OEM_2: result << '?'; break;
        case VK_OEM_5: result << '|'; break;
        case VK_OEM_3: result << '~'; break;

        default: break;
        }
    }
    else {

        switch (key_press_number) {

            case VK_TAB: result << "[TAB]"; break;
            case VK_CONTROL: result << "[CTRL]"; break;
            case VK_MENU: result << "[ALT]"; break;
            case VK_ESCAPE: result << "[ESC]"; break;
            case VK_BACK: result << "[BACKSPACE]"; break;
            case VK_RETURN: result << "[ENTER]"; break;
            case VK_DELETE: result << "[DELETE]"; break;
            case VK_INSERT: result << "[INSERT]"; break;
            case VK_LWIN: result << "[LEFT WINDOWS]"; break;
            case VK_RWIN: result << "[RIGHT WINDOWS]"; break;
            case VK_CAPITAL: result << "[CAPS LOCK]"; break;
            case VK_NUMLOCK: result << "[NUM LOCK]"; break;
            case VK_SCROLL: result << "[SCROLL LOCK]"; break;
            case VK_LEFT: result << "[LEFT ARROW]"; break;
            case VK_RIGHT: result << "[RIGHT ARROW]"; break;
            case VK_UP: result << "[UP ARROW]"; break;
            case VK_DOWN: result << "[DOWN ARROW]"; break;

            case 0xBC: result << ','; break;
            case 0xBE: result << '.'; break;
            case 0xBF: result << '/'; break;
            case 0xBA: result << ';'; break;
            case 0xDE: result << '\''; break;
            case 0xDB: result << '['; break;
            case 0xDD: result << ']'; break;
            case 0xDC: result << '\\'; break;
            case 0xC0: result << '`'; break;
            case 0xBD: result << '-'; break;
            case 0xBB: result << '='; break;
            case 32: result << " "; break;

            default:
                if (key_press_number >= '0' && key_press_number <= '9') {
                    result << char(key_press_number);
                } else if (key_press_number >= VK_F1 && key_press_number <= VK_F12) {
                    result << "[F" << (key_press_number - VK_F1 + 1) << "]";
                } else {
                    //result << "[UNKNOWN]";
                }
            break;
        }
    }

    return result.str();
}
