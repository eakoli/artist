/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include "app.hpp"

void balloon(canvas& cnv)
{
    // quadratic_curve_to
    cnv.begin_path();
    cnv.move_to({ 75, 25 });
    cnv.quadratic_curve_to({ 25, 25 }, { 25, 62.5 });
    cnv.quadratic_curve_to({ 25, 100 }, { 50, 100 });
    cnv.quadratic_curve_to({ 50, 120 }, { 30, 125 });
    cnv.quadratic_curve_to({ 60, 120 }, { 65, 100 });
    cnv.quadratic_curve_to({ 125, 100 }, { 125, 62.5 });
    cnv.quadratic_curve_to({ 125, 25 }, { 75, 25 });
}

void heart(canvas& cnv)
{
    // bezier_curve_to
    constexpr float y0 = 40, y1 = 50, y2 = 23, y3 = 90, y4 = 45, y5 = 75, y6 = 125;
    cnv.begin_path();
    cnv.move_to({ 75, y0 });
    cnv.bezier_curve_to({ 75, y4 }, { 70, y2 }, { 50, y2 });
    cnv.bezier_curve_to({ 20, y2 }, { 20, y1 }, { 20, y1 });
    cnv.bezier_curve_to({ 20, y5 }, { y0, y3 }, { 75, y6 });
    cnv.bezier_curve_to({ 110, y3 }, { 130, y5 }, { 130, y1 });
    cnv.bezier_curve_to({ 130, y1}, { 130, y2 }, { 100, y2 });
    cnv.bezier_curve_to({ 85, y2 }, { 75, y4 }, { 75, y0 });
    cnv.fill_style(color{ 0.2, 0, 0 }.opacity(0.4));
}

void basics(canvas& cnv)
{
    cnv.rect({ 20, 20, 100, 60 });
    cnv.fill_style(colors::navy_blue);
    cnv.fill_preserve();

    cnv.stroke_style(colors::antique_white.opacity(0.8));
    cnv.line_width(0.5);
    cnv.stroke();

    cnv.round_rect({ 40, 35, 120, 80 }, 8);
    cnv.fill_style(colors::light_sea_green.opacity(0.5));
    cnv.fill();

    cnv.move_to({ 10, 10 });
    cnv.line_to({ 100, 100 });
    cnv.line_width(10);
    cnv.stroke_style(colors::hot_pink);
    cnv.stroke();

    cnv.circle({{ 120, 80 }, 40});
    cnv.line_width(4);
    cnv.fill_style(colors::gold.opacity(0.5));
    cnv.stroke_style(colors::gold);
    cnv.fill_preserve();
    cnv.stroke();

    cnv.translate({ 120, 0 });
    balloon(cnv);
    cnv.stroke_style(colors::light_gray);
    cnv.stroke();

    cnv.translate({ -100, 100 });
    heart(cnv);
    cnv.line_width(2);
    cnv.stroke_style(color{ 0.8, 0, 0 });
    cnv.stroke_preserve();
    cnv.fill();
}

void draw(canvas& cnv)
{
    basics(cnv);

    cnv.scale({ 1.5, 1.5 });
    cnv.translate({ 150, 0 });
    cnv.rotate(0.8);
    basics(cnv);
}

int main(int argc, const char* argv[])
{
    return run_app(argc, argv);
}

