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


    const struct settings_t {
        Decorator background_color{bgcolor(Color::RGB(30, 40, 50))};
        float content_height{0.4f}, // Percentage
              content_width{0.25f} // Percentage
        ;
    } settings{};
    const struct fields_t {
        std::string title_text{"千乇ㄒ匚卄"};
        // Alt: ᖴᗴ丅ᑕᕼ
        // Alt: 乍ヨ卞亡廾
        // Alt: 千㠪ㄒ⼕廾
        struct subcommand_t
            // TODO: make a custom allocator for this (constexpr string_view?) returning const char *
        { std::string name, helptext; };
        std::vector<subcommand_t> subcommands{
            { "Shock", "TODO: Shock helptext" },
                { "Surveil", "TODO: Surveil helptext" },
                { "Triome", "TODO: Triome helptext" },
                { "Tapped", "TODO: Tapped helptext" },
                { "Snow", "TODO: Snow helptext" },
                { "Cycle", "TODO: Cycle helptext" },
                { "Tango", "TODO: Tango helptext" },
                { "Dual", "TODO: Dual helptext" }
        };
        std::vector<SUBCOMMAND> display_order{
            SUBCOMMAND::SHOCK,
                SUBCOMMAND::SURVEIL,
                SUBCOMMAND::TRIOME
        };
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
            for (size_t i{0}; i < fields.display_order.size(); ++i) { rv[i] = fields.subcommands[i].name; }
            return rv;
        }()
    };
    struct subcommand_menu_t {
        Component element;
        std::function<fields_t::subcommand_t()> get_selected;
    } subcommand_menu {
        .element = Menu(
                &subcommand_menu_data.names,
                &subcommand_menu_data.selected_item
                ),
            .get_selected = [&]()->fields_t::subcommand_t{
                return fields.subcommands[
                    static_cast<size_t>(
                            fields.display_order
                            [ subcommand_menu_data.selected_item ]
                            )
                ];
            }
    };
    struct helptext_display_t {
        std::function<Element()> make_element;
    } helptext_display {
        .make_element = [&]()->Element{
            return paragraph(subcommand_menu.get_selected().helptext)
                | dim;
        }
    };
    std::function<Element()> layout{
        [&]()->Element {
            return vbox({
                    title_display.element | border
                    | size(WIDTH, EQUAL,
                            static_cast<int>(
                                screen.dimx()*settings.content_width
                                )
                          ),
                    hbox({
                            subcommand_menu.element->Render() | border,
                            helptext_display.make_element() | border
                            })
                    | size(HEIGHT, EQUAL,
                            static_cast<int>(screen.dimy()*settings.content_height)
                          )
                    })
            | center | settings.background_color
                ;
        }
    };

    Component renderer = CatchEvent(
            Renderer(subcommand_menu.element, layout),
            [&](Event event) {
            if (event == Event::Return) { screen.ExitLoopClosure()(); return true; }
            return false;
            }
            );

    screen.Loop(renderer);

    return static_cast<SUBCOMMAND>(subcommand_menu_data.selected_item);
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
        default:
            return "Error";
    }
};
std::string to_string(const SUBCOMMAND subc)
{
    switch (subc)
    {
        case SUBCOMMAND::SHOCK:
            return "shock";
        case SUBCOMMAND::SURVEIL:
            return "surveil";
        case SUBCOMMAND::TRIOME:
            return "triome";
        case SUBCOMMAND::TAPPED:
            return "tapped";
        case SUBCOMMAND::SNOW:
            return "snow";
        case SUBCOMMAND::CYCLE:
            return "cycle";
        case SUBCOMMAND::TANGO:
            return "tango";
        case SUBCOMMAND::DUAL:
            return "dual";
        default:
            return "error";
    }
};
