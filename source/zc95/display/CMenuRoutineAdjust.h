#ifndef _CMENUROUTINEADJUST_H
#define _CMENUROUTINEADJUST_H

#include "CMenu.h"
#include "CDisplay.h"
#include "COptionsList.h"
#include "../core1/routines/CRoutine.h"
#include "../core1/CRoutineOutput.h"
#include "../core1/routines/CRoutines.h"
#include "../config.h"
#include "../ECButtons.h"
#include "../CGetButtonState.h"
#include "../AudioInput/CAudio.h"
#include "../Bluetooth/CBluetooth.h"

#include <string>
#include <vector>

class CMenuRoutineAdjust : public CMenu
{
    public:
        CMenuRoutineAdjust(
                CDisplay* display, 
                CRoutines::Routine routine, 
                CGetButtonState *buttons, 
                CRoutineOutput *routine_output, 
                CAudio *audio, 
                CBluetooth *bluetooth,
                CSavedSettings *saved_settings);
        ~CMenuRoutineAdjust();
        void button_pressed(Button button);
        void button_released(Button button);
        void adjust_rotary_encoder_change(int8_t change);
        void draw();
        void show();

    private:
        void set_options_on_multi_choice_list();
        void draw_horz_bar_graph(int16_t x, int16_t y, uint8_t width, uint8_t height, int16_t min_val, int16_t max_val, int16_t current_val, std::string UoM, hagl_color_t bar_colour);
        uint8_t choice_id_to_menu_index(struct menu_entry selected_menu, uint8_t choice_id);
        void increment_gain(uint8_t by);
        void decrement_gain(uint8_t by);
        void draw_bad_script_screen();
        void process_bluetooth_remote_keypress(CBluetoothRemote::keypress_t key);

        COptionsList *_routine_adjust_display_list = NULL;
        COptionsList *_routine_multi_choice_list = NULL;
        struct display_area _area;
        CDisplay* _display;
        struct routine_conf _active_routine_conf;
        bool _bt_enabled = false;
        queue_t _bt_keypress_queue = {0};
        CGetButtonState *_buttons;
        CRoutineOutput *_routine_output;
        CAudio *_audio;
        CBluetooth *_bluetooth = NULL;
        CSavedSettings *_saved_settings;
};

#endif
