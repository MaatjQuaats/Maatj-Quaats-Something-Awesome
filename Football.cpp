#include <splashkit.h>

struct player
{
    string p_name;
    int p_goals;
    int temp_goals;
    int pen_shootouts_1;
    int pen_shootouts_2;

    player()
    {
        this->p_goals = 0;
        this->temp_goals = 0;
        this->pen_shootouts_1 = 0;
        this->pen_shootouts_2 = 0;
    }
    string read_info(player &a)
    {
        a.p_name = read_line();
        return a.p_name;
    }
    void read_goals(player &a)
    {
        string b;
        write("Enter goals for " + a.p_name + ": ");
        b = read_line();
        while (!is_integer(b))
        {
            write_line("Enter a whole number!");
            write("Enter goals for " + a.p_name + ": ");
            b = read_line();
        }
        a.temp_goals = std::stoi(b);
    }
    void read_pens_1(player &a)
    {
        string b;
        write("Enter penalty shootouts for " + a.p_name + ": ");
        b = read_line();
        while (!is_integer(b))
        {
            write_line("Enter a whole number!");
            write("Enter penalty shootouts for " + a.p_name + ": ");
            b = read_line();
        }
        a.pen_shootouts_1 = std::stoi(b);
    }
    void read_pens_2(player &a)
    {
        string b;
        write("Enter penalty shootouts for " + a.p_name + ": ");
        b = read_line();
        while (!is_integer(b))
        {
            write_line("Enter a whole number!");
            write("Enter penalty shootouts for " + a.p_name + ": ");
            b = read_line();
        }
        a.pen_shootouts_2 = std::stoi(b);
    }
    int get_temp_goals(const player &a)
    {
        return a.temp_goals;
    }
    int get_pens_1(const player &a)
    {
        return a.pen_shootouts_1;
    }
    int get_pens_2(const player &a)
    {
        return a.pen_shootouts_2;
    }
    void record_goals(player &a)
    {
        a.p_goals += a.temp_goals;
    }
    void print_info(const player &a)
    {
        write_line("Name: " + a.p_name);
        write_line("Goals: " + std::to_string(a.p_goals));
    }
};

struct club
{
    string club_name;
    string players[2];

    string read_info(club &a)
    {
        a.club_name = read_line();
        return a.club_name;
    }
    string print_info(const club &a)
    {
        return a.club_name;
    }
    void add_player(player &a, player &b, club &c)
    {
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                write_line("Enter " + std::to_string(i + 1) + " player name for " + c.club_name + ":");
                c.players[i] = a.read_info(a);
                break;
            case 1:
                write_line("Enter " + std::to_string(i + 1) + " player name for " + c.club_name + ":");
                c.players[i] = b.read_info(b);
                break;
            }
        }
    }
};

struct championship
{
    string champ_name = "Mini Football Champions Cup 2025";
    string clubs[4];

    void add_club(club &a, club &b, club &c, club &d, championship &e)
    {
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                write_line("Enter the " + std::to_string(i + 1) + " club name: ");
                e.clubs[i] = a.read_info(a);
                break;
            case 1:
                write_line("Enter the " + std::to_string(i + 1) + " club name: ");
                e.clubs[i] = b.read_info(b);
                break;
            case 2:
                write_line("Enter the " + std::to_string(i + 1) + " club name: ");
                e.clubs[i] = c.read_info(c);
                break;
            case 3:
                write_line("Enter the " + std::to_string(i + 1) + " club name: ");
                e.clubs[i] = d.read_info(d);
                break;
            }
        }
    }
    void print_club(const championship &a)
    {
        for (int i = 0; i < 4; i++)
        {
            write_line(a.clubs[i]);
        }
    }
};

void print_semifixture(const championship &a)
{
    write_line(a.clubs[0] + " vs " + a.clubs[3]);
    write_line(a.clubs[1] + " vs " + a.clubs[2]);
}

void draw_semifixture(const championship &a)
{
    draw_text(a.clubs[0] + " vs " + a.clubs[3], color_black(), 20, 80);
    draw_text(a.clubs[1] + " vs " + a.clubs[2], color_black(), 20, 100);
}

void semiresult(const championship &a, player &p1, player &p2, player &p3, player &p4, player &p5, player &p6, player &p7, player &p8)
{
    write_line("Enter goals for " + a.clubs[0] + ":");
    p1.read_goals(p1);
    p1.record_goals(p1);
    p2.read_goals(p2);
    p2.record_goals(p2);
    write_line("Enter goals for " + a.clubs[3] + ":");
    p7.read_goals(p7);
    p7.record_goals(p7);
    p8.read_goals(p8);
    p8.record_goals(p8);
    if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) == p7.get_temp_goals(p7) + p8.get_temp_goals(p8))
    {
        p1.read_pens_1(p1);
        p2.read_pens_1(p2);
        p7.read_pens_1(p7);
        p8.read_pens_1(p8);
    }
    write_line("Enter goals for " + a.clubs[1] + ":");
    p3.read_goals(p3);
    p3.record_goals(p3);
    p4.read_goals(p4);
    p4.record_goals(p4);
    write_line("Enter goals for " + a.clubs[2] + ":");
    p5.read_goals(p5);
    p5.record_goals(p5);
    p6.read_goals(p6);
    p6.record_goals(p6);
    if (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) == p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
    {
        p3.read_pens_1(p3);
        p4.read_pens_1(p4);
        p5.read_pens_1(p5);
        p6.read_pens_1(p6);
    }
}

void print_semiresult(const championship &a, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    write_line(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_1(p1) + p2.get_pens_1(p2)) + ")" + " - " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_1(p7) + p8.get_pens_1(p8)) + ")" + " " + a.clubs[3]);
    write_line(a.clubs[1] + " " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_1(p3) + p4.get_pens_1(p4)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_1(p5) + p6.get_pens_1(p6)) + ")" + " " + a.clubs[2]);
}

void draw_semiresult(const championship &a, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    draw_text(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_1(p1) + p2.get_pens_1(p2)) + ")" + " - " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_1(p7) + p8.get_pens_1(p8)) + ")" + " " + a.clubs[3], color_black(), 20, 80);
    draw_text(a.clubs[1] + " " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_1(p3) + p4.get_pens_1(p4)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_1(p5) + p6.get_pens_1(p6)) + ")" + " " + a.clubs[2], color_black(), 20, 100);
}

void print_finalfixture(const championship &a, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6))
    {
        write_line(a.clubs[0] + " vs " + a.clubs[1]);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line(a.clubs[3] + " vs " + a.clubs[1]);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line(a.clubs[0] + " vs " + a.clubs[2]);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line(a.clubs[3] + " vs " + a.clubs[2]);
    }
}

void draw_finalfixture(const championship &a, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6))
    {
        draw_text(a.clubs[0] + " vs " + a.clubs[1], color_black(), 20, 80);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[3] + " vs " + a.clubs[1], color_black(), 20, 100);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[0] + " vs " + a.clubs[2], color_black(), 20, 120);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[3] + " vs " + a.clubs[2], color_black(), 20, 140);
    }
}

void finalresult(const championship &a, player &p1, player &p2, player &p3, player &p4, player &p5, player &p6, player &p7, player &p8)
{
    if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6))
    {
        write_line("Enter goals for " + a.clubs[0] + ":");
        p1.read_goals(p1);
        p1.record_goals(p1);
        p2.read_goals(p2);
        p2.record_goals(p2);
        write_line("Enter goals for " + a.clubs[1] + ":");
        p3.read_goals(p3);
        p3.record_goals(p3);
        p4.read_goals(p4);
        p4.record_goals(p4);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) == p3.get_temp_goals(p3) + p4.get_temp_goals(p4))
        {
            p1.read_pens_2(p1);
            p2.read_pens_2(p2);
            p3.read_pens_2(p3);
            p4.read_pens_2(p4);
        }
        write_line(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_2(p1) + p2.get_pens_2(p2)) + ")" + " - " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_2(p3) + p4.get_pens_2(p4)) + ")" + " " + a.clubs[1]);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p3.get_temp_goals(p3) + p4.get_temp_goals(p4) || p1.get_pens_2(p1) + p2.get_pens_2(p2) > p3.get_pens_2(p3) + p4.get_pens_2(p4))
        {
            write_line(a.clubs[0] + " is the champion");
        }
        else
            write_line(a.clubs[1] + " is the champion");
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line("Enter goals for " + a.clubs[3] + ":");
        p7.read_goals(p7);
        p7.record_goals(p7);
        p8.read_goals(p8);
        p8.record_goals(p8);
        write_line("Enter goals for " + a.clubs[1] + ":");
        p3.read_goals(p3);
        p3.record_goals(p3);
        p4.read_goals(p4);
        p4.record_goals(p4);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) == p3.get_temp_goals(p3) + p4.get_temp_goals(p4))
        {
            p7.read_pens_2(p7);
            p8.read_pens_2(p8);
            p3.read_pens_2(p3);
            p4.read_pens_2(p4);
        }
        write_line(a.clubs[3] + " " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_2(p7) + p8.get_pens_2(p8)) + ")" + " - " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_2(p3) + p4.get_pens_2(p4)) + ")" + " " + a.clubs[1]);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) > p3.get_temp_goals(p3) + p4.get_temp_goals(p4) || p7.get_pens_2(p7) + p8.get_pens_2(p8) > p3.get_pens_2(p3) + p4.get_pens_2(p4))
        {
            write_line(a.clubs[3] + " is the champion");
        }
        else
            write_line(a.clubs[1] + " is the champion");
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line("Enter goals for " + a.clubs[0] + ":");
        p1.read_goals(p1);
        p1.record_goals(p1);
        p2.read_goals(p2);
        p2.record_goals(p2);
        write_line("Enter goals for " + a.clubs[2] + ":");
        p5.read_goals(p5);
        p5.record_goals(p5);
        p6.read_goals(p6);
        p6.record_goals(p6);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) == p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            p1.read_pens_1(p1);
            p2.read_pens_1(p2);
            p5.read_pens_1(p5);
            p6.read_pens_1(p6);
        }
        write_line(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_2(p1) + p2.get_pens_2(p2)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_2(p5) + p6.get_pens_2(p6)) + ")" + " " + a.clubs[2]);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            write_line(a.clubs[0] + " is the champion");
        }
        else
            write_line(a.clubs[2] + " is the champion");
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        write_line("Enter goals for " + a.clubs[3] + ":");
        p7.read_goals(p7);
        p7.record_goals(p7);
        p8.read_goals(p8);
        p8.record_goals(p8);
        write_line("Enter goals for " + a.clubs[2] + ":");
        p5.read_goals(p5);
        p5.record_goals(p5);
        p6.read_goals(p6);
        p6.record_goals(p6);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) == p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            p7.read_pens_1(p7);
            p8.read_pens_1(p8);
            p5.read_pens_1(p5);
            p6.read_pens_1(p6);
        }
        write_line(a.clubs[3] + " " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_2(p7) + p8.get_pens_2(p8)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_2(p5) + p6.get_pens_2(p6)) + ")" + " " + a.clubs[2]);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            write_line(a.clubs[3] + " is the champion");
        }
        else
            write_line(a.clubs[2] + " is the champion");
    }
}

void draw_finalresult(const championship &a, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6))
    {
        draw_text(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_2(p1) + p2.get_pens_2(p2)) + ")" + " - " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_2(p3) + p4.get_pens_2(p4)) + ")" + " " + a.clubs[1], color_black(), 20, 80);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p3.get_temp_goals(p3) + p4.get_temp_goals(p4) || p1.get_pens_2(p1) + p2.get_pens_2(p2) > p3.get_pens_2(p3) + p4.get_pens_2(p4))
        {
            draw_text(a.clubs[0] + " is the champion", color_black(), 20, 100);
        }
        else
            draw_text(a.clubs[1] + " is the champion", color_black(), 20, 100);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) > p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[3] + " " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_2(p7) + p8.get_pens_2(p8)) + ")" + " - " + std::to_string(p3.get_temp_goals(p3) + p4.get_temp_goals(p4)) + "(" + std::to_string(p3.get_pens_2(p3) + p4.get_pens_2(p4)) + ")" + " " + a.clubs[1], color_black(), 20, 80);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) > p3.get_temp_goals(p3) + p4.get_temp_goals(p4) || p7.get_pens_2(p7) + p8.get_pens_2(p8) > p3.get_pens_2(p3) + p4.get_pens_2(p4))
        {
            draw_text(a.clubs[3] + " is the champion", color_black(), 20, 100);
        }
        else
            draw_text(a.clubs[1] + " is the champion", color_black(), 20, 100);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) > p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[0] + " " + std::to_string(p1.get_temp_goals(p1) + p2.get_temp_goals(p2)) + "(" + std::to_string(p1.get_pens_2(p1) + p2.get_pens_2(p2)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_2(p5) + p6.get_pens_2(p6)) + ")" + " " + a.clubs[2], color_black(), 20, 80);
        if (p1.get_temp_goals(p1) + p2.get_temp_goals(p2) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            draw_text(a.clubs[0] + " is the champion", color_black(), 20, 100);
        }
        else
            draw_text(a.clubs[2] + " is the champion", color_black(), 20, 100);
    }
    else if ((p1.get_temp_goals(p1) + p2.get_temp_goals(p2) < p7.get_temp_goals(p7) + p8.get_temp_goals(p8) || p1.get_pens_1(p1) + p2.get_pens_1(p2) < p7.get_pens_1(p7) + p8.get_pens_1(p8)) && (p3.get_temp_goals(p3) + p4.get_temp_goals(p4) < p5.get_temp_goals(p5) + p6.get_temp_goals(p6) || p3.get_pens_1(p3) + p4.get_pens_1(p4) < p5.get_pens_1(p5) + p6.get_pens_1(p6)))
    {
        draw_text(a.clubs[3] + " " + std::to_string(p7.get_temp_goals(p7) + p8.get_temp_goals(p8)) + "(" + std::to_string(p7.get_pens_2(p7) + p8.get_pens_2(p8)) + ")" + " - " + std::to_string(p5.get_temp_goals(p5) + p6.get_temp_goals(p6)) + "(" + std::to_string(p5.get_pens_2(p5) + p6.get_pens_2(p6)) + ")" + " " + a.clubs[2], color_black(), 20, 80);
        if (p7.get_temp_goals(p7) + p8.get_temp_goals(p8) > p5.get_temp_goals(p5) + p6.get_temp_goals(p6))
        {
            draw_text(a.clubs[3] + " is the champion", color_black(), 20, 100);
        }
        else
            draw_text(a.clubs[2] + " is the champion", color_black(), 20, 100);
    }
}

void user_interface(const championship &c, player p1, player p2, player p3, player p4, player p5, player p6, player p7, player p8)
{
    string options[5] = {
        "1. Players",
        "2. Semi Fixtures",
        "3. Semi Results",
        "4. Final Fixture",
        "5. Final Result",
    };
    string clubs_options[4] = {
        "1. " + c.clubs[0],
        "2. " + c.clubs[1],
        "3. " + c.clubs[2],
        "4. " + c.clubs[3],
    };
    int current_window = 0;
    open_window(c.champ_name, 400, 500);
    while (!quit_requested())
    {
        process_events();
        if (current_window == 0)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Mini Champions Cup 2025", color_white(), 30, 20);
            for (int i = 0; i < 5; i++)
            {
                int y = 105 + i * 40;
                fill_circle(color_aqua(), 25, y, 10);
            }
            for (int i = 0; i < 5; i++)
            {
                int y = 100 + i * 40;
                draw_text(options[i], color_black(), 20, y);
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 105, 10))
            {
                current_window = 1;
            }
            else if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 145, 10))
            {
                current_window = 2;
            }
            else if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 185, 10))
            {
                current_window = 3;
            }
            else if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 225, 10))
            {
                current_window = 4;
            }
            else if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 265, 10))
            {
                current_window = 5;
            }
        }
        else if (current_window == 1)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Players", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            for (int i = 0; i < 4; i++)
            {
                int y = 105 + i * 40;
                fill_circle(color_aqua(), 25, y, 10);
            }
            for (int i = 0; i < 4; i++)
            {
                int y = 100 + i * 40;
                draw_text(clubs_options[i], color_black(), 20, y);
            }
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 105, 10))
            {
                current_window = 6;
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 145, 10))
            {
                current_window = 7;
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 185, 10))
            {
                current_window = 8;
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_circle(mouse_x(), mouse_y(), 25, 225, 10))
            {
                current_window = 9;
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
        }
        else if (current_window == 2)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Semi Fixtures", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_semifixture(c);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
        }
        else if (current_window == 3)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Semi Results", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_semiresult(c, p1, p2, p3, p4, p5, p6, p7, p8);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
        }
        else if (current_window == 4)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Final Fixture", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_finalfixture(c, p1, p2, p3, p4, p5, p6, p7, p8);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
        }
        else if (current_window == 5)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Final Result", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_finalresult(c, p1, p2, p3, p4, p5, p6, p7, p8);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 0;
            }
        }
        else if (current_window == 6)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Players", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_rectangle(color_black(), 20, 80, 100, 150);
            draw_rectangle(color_black(), 280, 80, 100, 150);
            draw_text(p1.p_name, color_black(), 30, 90);
            draw_text(p2.p_name, color_black(), 290, 90);
            draw_text(c.clubs[0], color_black(), 30, 110);
            draw_text(c.clubs[0], color_black(), 290, 110);
            draw_text("Goals: " + std::to_string(p1.p_goals), color_black(), 30, 130);
            draw_text("Goals: " + std::to_string(p1.p_goals), color_black(), 290, 130);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 1;
            }
        }
        else if (current_window == 7)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Players", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_rectangle(color_black(), 20, 80, 100, 150);
            draw_rectangle(color_black(), 280, 80, 100, 150);
            draw_text(p3.p_name, color_black(), 30, 90);
            draw_text(p4.p_name, color_black(), 290, 90);
            draw_text(c.clubs[1], color_black(), 30, 110);
            draw_text(c.clubs[1], color_black(), 290, 110);
            draw_text("Goals: " + std::to_string(p3.p_goals), color_black(), 30, 130);
            draw_text("Goals: " + std::to_string(p4.p_goals), color_black(), 290, 130);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 1;
            }
        }
        else if (current_window == 8)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Players", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_rectangle(color_black(), 20, 80, 100, 150);
            draw_rectangle(color_black(), 280, 80, 100, 150);
            draw_text(p5.p_name, color_black(), 30, 90);
            draw_text(p6.p_name, color_black(), 290, 90);
            draw_text(c.clubs[2], color_black(), 30, 110);
            draw_text(c.clubs[2], color_black(), 290, 110);
            draw_text("Goals: " + std::to_string(p5.p_goals), color_black(), 30, 130);
            draw_text("Goals: " + std::to_string(p6.p_goals), color_black(), 290, 130);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 1;
            }
        }
        else if (current_window == 9)
        {
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 400, 60);
            draw_text("Players", color_white(), 30, 20);
            fill_rectangle(color_black(), 0, 440, 400, 60);
            draw_rectangle(color_black(), 20, 80, 100, 150);
            draw_rectangle(color_black(), 280, 80, 100, 150);
            draw_text(p7.p_name, color_black(), 30, 90);
            draw_text(p8.p_name, color_black(), 290, 90);
            draw_text(c.clubs[3], color_black(), 30, 110);
            draw_text(c.clubs[3], color_black(), 290, 110);
            draw_text("Goals: " + std::to_string(p7.p_goals), color_black(), 30, 130);
            draw_text("Goals: " + std::to_string(p8.p_goals), color_black(), 290, 130);
            draw_text("Return", color_white(), 30, 460);
            if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 440, 400, 60))
            {
                current_window = 1;
            }
        }
        refresh_screen(90);
    }
}

int main()
{
    championship c;
    club c1, c2, c3, c4;
    player p1, p2, p3, p4, p5, p6, p7, p8;
    c.add_club(c1, c2, c3, c4, c);
    c1.add_player(p1, p2, c1);
    c2.add_player(p3, p4, c2);
    c3.add_player(p5, p6, c3);
    c4.add_player(p7, p8, c4);
    print_semifixture(c);
    semiresult(c, p1, p2, p3, p4, p5, p6, p7, p8);
    print_semiresult(c, p1, p2, p3, p4, p5, p6, p7, p8);
    print_finalfixture(c, p1, p2, p3, p4, p5, p6, p7, p8);
    finalresult(c, p1, p2, p3, p4, p5, p6, p7, p8);
    user_interface(c, p1, p2, p3, p4, p5, p6, p7, p8);
    return 0;
}