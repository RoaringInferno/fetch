#include "main_menu.hpp"

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include <vector>
#include <functional>
#include <string>

#include <cstdio>

SUBCOMMAND run_main_menu()
{
    using namespace ftxui;
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    SUBCOMMAND selected_subcommand{SUBCOMMAND::EXIT};


    struct settings_t {
        Color background_color{Color::RGB(30, 40, 50)};
        float content_height{0.4f}, // Percentage
              content_width{0.3f} // Percentage
        ;
    } settings{};
    const struct fields_t {
        std::string title_text{"千乇ㄒ匚卄"};
        std::string select_button_label{"Select"}; // 丂乇ㄥ乇匚ㄒ
        std::vector<SUBCOMMAND> display_order{
            SUBCOMMAND::SHOCK,
                SUBCOMMAND::SURVEIL,
                SUBCOMMAND::TRIOME,
                SUBCOMMAND::DUAL
        }; // TODO: MODIFY HERE TO ADD COMMANDS
    } fields{};
    struct title_display_t {
        Element element;
    } title_display{
        .element = text(fields.title_text) | bold | center
    };
    struct subcommand_menu_data_t {
        int selected_item{0};
        std::vector<std::string> names; // Converts display order to names
    } subcommand_menu_data {
        .names = [&]()->std::vector<std::string> {
            std::vector<std::string> rv(fields.display_order.size());
            for (size_t i{0}; i < fields.display_order.size(); ++i)
            {
                rv[i] = to_String(fields.display_order[i]);
            }
            return rv;
        }()
    };
    std::function<SUBCOMMAND()> get_selected_subcommand =
        [&]()->SUBCOMMAND{
            return fields.display_order[subcommand_menu_data.selected_item];
        };
    struct subcommand_menu_t {
        Component element;
    } subcommand_menu {
        .element = Menu(
                &subcommand_menu_data.names,
                &subcommand_menu_data.selected_item
                )
    };
    struct {
        Component element;
    } select_button {
        .element = Button({
                .on_click = [&](){
                selected_subcommand = get_selected_subcommand();
                screen.ExitLoopClosure()();
                },
                .transform = [&](const EntryState &state)->Element {
                Element rv{text(fields.select_button_label)};
                if (state.focused) {
                rv |= bgcolor(Color::White);
                rv |= color(settings.background_color);
                }
                return rv;
                }
                })
    };
    struct {
        Component element;
    } exit_button {
        .element = Button({
                .on_click = [&](){
                screen.ExitLoopClosure()();
                },
                .transform = [&](const EntryState &state)->Element {
                Element rv{text("Exit")};
                if (state.focused) {
                rv |= bgcolor(Color::White);
                rv |= color(settings.background_color);
                }
                return rv;
                }
                })
    };
    struct helptext_display_t {
        std::function<Element()> make_element;
    } helptext_display {
        .make_element = [&]()->Element{
            return vbox({
                    paragraph(helptext(get_selected_subcommand()))
                    | dim | flex,
                    hbox({
                            exit_button.element->Render(),
                            filler(),
                            select_button.element->Render()
                            })
                    });
        }
    };
    std::function<Element()> layout{
        [&]()->Element {
            return vbox({
                    title_display.element | border
                    | size(WIDTH, EQUAL, static_cast<int>(
                                screen.dimx()*settings.content_width
                                )),
                    hbox({
                            subcommand_menu.element->Render() | border,
                            helptext_display.make_element() | border | flex
                            })
                    | size(HEIGHT, EQUAL, static_cast<int>(
                                screen.dimy()*settings.content_height
                                ))
                    })
            | center | bgcolor(settings.background_color)
                ;
        }
    };

    Component interactibles{Container::Horizontal({
            subcommand_menu.element,
            exit_button.element,
            select_button.element
            })};
    Component base_renderer{Renderer(interactibles, layout)};
    Component menu_listener{CatchEvent(base_renderer,
            [&](Event event)->bool {
            if (!subcommand_menu.element->Focused()) {
            return false;
            }
            if (event == Event::Return) {
            selected_subcommand = get_selected_subcommand();
            screen.ExitLoopClosure()();
            return true;
            }
            return false;
            }
            )};

    Component renderer{menu_listener};
    screen.Loop(renderer);

    return selected_subcommand;
}

std::string to_String(const SUBCOMMAND subc)
{
    switch (subc)
    {
        case SUBCOMMAND::SHOCK:
            return "Shock";
        case SUBCOMMAND::SURVEIL:
            return "Surveil";
        case SUBCOMMAND::TRIOME:
            return "Triome";
        case SUBCOMMAND::TAPPED:
            return "Tapped";
        case SUBCOMMAND::SNOW:
            return "Snow";
        case SUBCOMMAND::CYCLE:
            return "Cycle";
        case SUBCOMMAND::TANGO:
            return "Tango";
        case SUBCOMMAND::DUAL:
            return "Dual";
        case SUBCOMMAND::EXIT:
            return "Exit";
        default:
            return "Error";
    }
};
std::string to_FancyString(const SUBCOMMAND subc)
{
    switch (subc)
    {
        case SUBCOMMAND::SHOCK:
            return "丂卄ㄖ匚Ҝ";
        case SUBCOMMAND::SURVEIL:
            return "丂ㄩ尺ᐯ乇丨ㄥ";
        case SUBCOMMAND::TRIOME:
            return "ㄒ尺丨ㄖ爪乇";
        case SUBCOMMAND::TAPPED:
            return "ㄒ卂卩卩乇ᗪ";
        case SUBCOMMAND::SNOW:
            return "丂几ㄖ山";
        case SUBCOMMAND::CYCLE:
            return "匚ㄚ匚ㄥ乇";
        case SUBCOMMAND::TANGO:
            return "ㄒ卂几Ꮆㄖ";
        case SUBCOMMAND::DUAL:
            return "ᗪㄩ卂ㄥ";
        case SUBCOMMAND::EXIT:
            return "乇乂丨ㄒ";
        default:
            return "乇尺尺ㄖ尺";
    }
};
std::string helptext(const SUBCOMMAND subc)
{
    switch (subc)
    {
        case SUBCOMMAND::SHOCK:
            return "TODO: Shock helptext";
        case SUBCOMMAND::SURVEIL:
            return "TODO: Surveil helptext";
        case SUBCOMMAND::TRIOME:
            return "TODO: Triome helptext";
        case SUBCOMMAND::TAPPED:
            return "TODO: Tapped helptext";
        case SUBCOMMAND::SNOW:
            return "TODO: Snow helptext";
        case SUBCOMMAND::CYCLE:
            return "TODO: Cycle helptext";
        case SUBCOMMAND::TANGO:
            return "TODO: Tango helptext";
        case SUBCOMMAND::DUAL:
            return "TODO: Dual helptext";
        case SUBCOMMAND::EXIT:
            return "Exit the application";
        default:
            return "Error helptext";
    }
}
