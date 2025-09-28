#include <splashkit.h>

const int CLUBS = 4;                           // A league has only 4 clubs
const int PLAYERS_PER_CLUB = 2;                // Each club has 2 players
const int MATCHES = (CLUBS * (CLUBS - 1)) / 2; // C(4, 2)
const int MAX_USERS = 16;                      // Only 16 managers

class player
{
private:
    string p_name;
    int p_goals;
    int temp_goals;

public:
    player()
    {
        this->p_goals = 0;
        this->temp_goals = 0;
    }
    string read_info(player &a)
    {
        a.p_name = read_line();
        while (a.p_name.empty())
        {
            write_line("Seems like you have wrong with typing. You can try again !");
            a.p_name = read_line();
        }
        return a.p_name;
    }
    void read_goals(player &a)
    {
        string b;
        write("Enter goals for " + a.p_name + ": ");
        b = read_line();
        while (!is_integer(b) || std::stoi(b) < 0)
        {
            write_line("Enter a whole number!");
            write("Enter goals for " + a.p_name + ": ");
            b = read_line();
        }
        a.temp_goals = std::stoi(b);
    }
    int get_temp_goals(player a)
    {
        return a.temp_goals;
    }
    void record_goals(player &a)
    {
        a.p_goals += a.temp_goals;
        a.temp_goals = 0;
    }
    player get_player(const player &a)
    {
        return a;
    }
    string get_name(const player &a)
    {
        return a.p_name;
    }
    int get_goals(const player &a)
    {
        return a.p_goals;
    }
};

class club
{
private:
    string club_name;
    player players[PLAYERS_PER_CLUB];

public:
    string read_info(club &a)
    {
        a.club_name = read_line();
        while (a.club_name.empty())
        {
            write_line("Seems like you have wrong with typing. You can try again !");
            a.club_name = read_line();
        }
        return a.club_name;
    }
    string print_info(club a)
    {
        return a.club_name;
    }
    club get_club(const club &c)
    {
        return c;
    }
    void add_player(player &a, player &b, club &c)
    {
        for (int i = 0; i < 2; i++)
        {
            switch (i)
            {
            case 0:
                write_line("Enter the " + std::to_string(i + 1) + " player name for " + c.club_name + ":");
                a.read_info(a);
                c.players[i] = a;
                break;
            case 1:
                write_line("Enter the " + std::to_string(i + 1) + " player name for " + c.club_name + ":");
                b.read_info(b);
                c.players[i] = b;
                break;
            }
        }
    }
    string get_name(const club &c)
    {
        return c.club_name;
    }
    player &get_player_ref(int idx)
    {
        return players[idx];
    }
};

class championship
{
private:
    string champ_name = "Mini Football Champions League 2025";
    club clubs[CLUBS];
    int played[CLUBS];         // Store number of games for each club
    int won[CLUBS];            // Store number of victories for each club
    int drawn[CLUBS];          // Store number of draw games for each club
    int lost[CLUBS];           // Store number of defeats for each club
    int gf[CLUBS];             // Goals for of each club
    int ga[CLUBS];             // Goals against of each club
    int home[MATCHES];         // Store the index of a club playing at home for each match
    int away[MATCHES];         // Store the index of a club playing away for each match
    int m_home_goals[MATCHES]; // Store number of goals for home club
    int m_away_goals[MATCHES]; // Store number of goals for away club
    bool played_flag[MATCHES]; // The state of a match (false ~ unplayed/true ~ played)
    int fixture_count;         // Count number of matches

public:
    championship()
    {
        this->fixture_count = 0;
        for (int i = 0; i < CLUBS; i++)
        {
            this->played[i] = 0;
            this->won[i] = 0;
            this->drawn[i] = 0;
            this->lost[i] = 0;
            this->gf[i] = 0;
            this->ga[i] = 0;
        }
        for (int i = 0; i < MATCHES; i++)
        {
            this->home[i] = 0;
            this->away[i] = 1;
            this->m_home_goals[i] = 0;
            this->m_away_goals[i] = 0;
            this->played_flag[i] = false;
        }
    }
    int points(int i, const int won[], const int drawn[]) // Points for a club
    {
        return won[i] * 3 + drawn[i];
    }
    int gd(int i, const int gf[], const int ga[]) // Goals difference for a club
    {
        return gf[i] - ga[i];
    }
    void sort_table(int order[CLUBS]) // Sort table by points, then goal difference, then goals scored, then club name
    {
        for (int i = 0; i < CLUBS; i++)
        {
            order[i] = i;
        }

        for (int i = 0; i < CLUBS - 1; i++)
        {
            for (int j = 0; j < CLUBS - 1 - i; j++)
            {
                int L = order[j];
                int R = order[j + 1];
                bool swap_needed = false;

                int pL = points(L, won, drawn);
                int pR = points(R, won, drawn);
                if (pL < pR)
                {
                    swap_needed = true;
                }
                else if (pL == pR)
                {
                    int gdL = gd(L, gf, ga);
                    int gdR = gd(R, gf, ga);
                    if (gdL < gdR)
                    {
                        swap_needed = true;
                    }
                    else if (gdL == gdR)
                    {
                        if (gf[L] < gf[R])
                            swap_needed = true;
                        else if (gf[L] == gf[R])
                        {
                            if (clubs[L].get_name(clubs[L]) > clubs[R].get_name(clubs[R]))
                                swap_needed = true;
                        }
                    }
                }

                if (swap_needed) // Swap if needed
                {
                    int t = order[j];
                    order[j] = order[j + 1];
                    order[j + 1] = t;
                }
            }
        }
    }
    void print_table()
    {
        int order[CLUBS];
        sort_table(order);

        write_line("");
        write_line("Standings:");
        write_line("Pos\tClub\tP\tW\tD\tL\tGF\tGA\tGD\tPts");

        for (int pos = 0; pos < CLUBS; pos++)
        {
            int i = order[pos];
            int gdv = gd(i, gf, ga);
            int pts = points(i, won, drawn);

            write_line(std::to_string(pos + 1) + "\t" + clubs[i].get_name(clubs[i]) + "\t" + std::to_string(played[i]) + "\t" + std::to_string(won[i]) + "\t" + std::to_string(drawn[i]) + "\t" + std::to_string(lost[i]) + "\t" + std::to_string(gf[i]) + "\t" + std::to_string(ga[i]) + "\t" + std::to_string(gdv) + "\t" + std::to_string(pts));
        }
    }
    void print_top_scorers() // Print top scorers (sorted list of players by goals)
    {
        string pname[CLUBS * PLAYERS_PER_CLUB];
        string cname[CLUBS * PLAYERS_PER_CLUB];
        int goals[CLUBS * PLAYERS_PER_CLUB];
        int idx = 0;
        for (int c = 0; c < CLUBS; c++)
        {
            for (int p = 0; p < PLAYERS_PER_CLUB; p++)
            {
                pname[idx] = clubs[c].get_player_ref(p).get_name(clubs[c].get_player_ref(p));
                cname[idx] = clubs[c].get_name(clubs[c]);
                goals[idx] = clubs[c].get_player_ref(p).get_goals(clubs[c].get_player_ref(p));
                idx++;
            }
        }
        for (int i = 0; i < idx - 1; i++)
        {
            for (int j = 0; j < idx - 1 - i; j++)
            {
                bool swap_needed = false;
                if (goals[j] < goals[j + 1])
                    swap_needed = true;
                else if (goals[j] == goals[j + 1])
                {
                    if (cname[j] > cname[j + 1])
                        swap_needed = true;
                    else if (cname[j] == cname[j + 1])
                    {
                        if (pname[j] > pname[j + 1])
                            swap_needed = true;
                    }
                }
                if (swap_needed)
                {
                    int tg = goals[j];
                    goals[j] = goals[j + 1];
                    goals[j + 1] = tg;
                    string tn = pname[j];
                    pname[j] = pname[j + 1];
                    pname[j + 1] = tn;
                    string tc = cname[j];
                    cname[j] = cname[j + 1];
                    cname[j + 1] = tc;
                }
            }
        }

        write_line("");
        write_line("Top Scorers:");
        write_line("Rank\tPlayer (Club)\tGoals");
        for (int i = 0; i < idx; i++)
        {
            write_line(std::to_string(i + 1) + "\t" + pname[i] + " (" + cname[i] + ")\t" + std::to_string(goals[i]));
        }
    }
    void build_fixtures() // Build the fixture list (every club plays every other club once)
    {
        for (int i = 0; i < CLUBS; i++)
        {
            for (int j = i + 1; j < CLUBS; j++)
            {
                home[fixture_count] = i;
                away[fixture_count] = j;
                m_home_goals[fixture_count] = 0;
                m_away_goals[fixture_count] = 0;
                played_flag[fixture_count] = false;
                fixture_count++;
            }
        }
    }
    int input_goals_for_club(int ci) // Prompt for goals for each player in a club for a match
    {
        write_line("Enter goals for " + clubs[ci].get_name(clubs[ci]) + " players (this match):");
        int team_total = 0;

        for (int p = 0; p < PLAYERS_PER_CLUB; p++)
        {
            player &pl = clubs[ci].get_player_ref(p);
            pl.read_goals(pl);
            team_total += pl.get_temp_goals(pl);
        }
        for (int p = 0; p < PLAYERS_PER_CLUB; p++)
        {
            player &pl = clubs[ci].get_player_ref(p);
            pl.record_goals(pl);
        }
        return team_total;
    }
    void update_table(int ci_home, int ci_away, int hg, int ag)
    {
        played[ci_home]++;
        played[ci_away]++;
        gf[ci_home] += hg;
        ga[ci_home] += ag;
        gf[ci_away] += ag;
        ga[ci_away] += hg;

        if (hg > ag)
        {
            won[ci_home]++;
            lost[ci_away]++;
        }
        else if (hg < ag)
        {
            won[ci_away]++;
            lost[ci_home]++;
        }
        else
        {
            drawn[ci_home]++;
            drawn[ci_away]++;
        }
    }
    void add_club(club &a, club &b, club &c, club &d, championship &e)
    {
        club *arr[4] = {&a, &b, &c, &d};

        for (int i = 0; i < 4; i++)
        {
            write_line("Enter the " + std::to_string(i + 1) + " club name: ");
            arr[i]->read_info(*arr[i]);

            player p1, p2;
            arr[i]->add_player(p1, p2, *arr[i]);

            e.clubs[i] = *arr[i];
        }
    }
    void user_interface(const championship &c)
    {
        string options[5] = {
            "1. Players",
            "2. Fixtures",
            "3. Results",
            "4. Table",
            "5. Top Scorers",
        };

        string clubs_options[CLUBS];
        for (int i = 0; i < CLUBS; i++)
        {
            clubs_options[i] = std::to_string(i + 1) + ". " + clubs[i].get_name(clubs[i]);
        }
        int current_window = 0;

        open_window(champ_name, 540, 580);

        while (!quit_requested())
        {
            process_events();
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 540, 64);
            if (current_window == 0)
            {
                draw_text(c.champ_name, color_white(), 16, 20);
            }
            else if (current_window == 1)
            {
                draw_text("Players <Select Club>", color_white(), 16, 20);
            }
            else if (current_window >= 6 && current_window <= 9)
            {
                draw_text("Players", color_white(), 16, 20);
            }
            else if (current_window == 2)
            {
                draw_text("Fixtures", color_white(), 16, 20);
            }
            else if (current_window == 3)
            {
                draw_text("Results", color_white(), 16, 20);
            }
            else if (current_window == 4)
                draw_text("Table", color_white(), 16, 20);
            else if (current_window == 5)
            {
                draw_text("Top Scorers", color_white(), 16, 20);
            }
            if (current_window != 0)
            {
                fill_rectangle(color_black(), 0, 540, 540, 60);
                draw_text("Return", color_white(), 16, 540);
            }

            if (current_window == 0)
            {
                int ydot1 = 110;
                int ydot2 = 154;
                int ydot3 = 198;
                int ydot4 = 242;
                int ydot5 = 286;

                int ytxt1 = ydot1 - 6;
                int ytxt2 = ydot2 - 6;
                int ytxt3 = ydot3 - 6;
                int ytxt4 = ydot4 - 6;
                int ytxt5 = ydot5 - 6;

                fill_circle(color_aqua(), 30, ydot1, 10);
                fill_circle(color_aqua(), 30, ydot2, 10);
                fill_circle(color_aqua(), 30, ydot3, 10);
                fill_circle(color_aqua(), 30, ydot4, 10);
                fill_circle(color_aqua(), 30, ydot5, 10);

                draw_text("1. Players", color_black(), 60, ytxt1);
                draw_text("2. Fixtures", color_black(), 60, ytxt2);
                draw_text("3. Results", color_black(), 60, ytxt3);
                draw_text("4. Table", color_black(), 60, ytxt4);
                draw_text("5. Top Scorers", color_black(), 60, ytxt5);

                if (mouse_clicked(LEFT_BUTTON))
                {
                    int mx = mouse_x(), my = mouse_y();

                    if (point_in_circle(mx, my, 30, ydot1, 10))
                    {
                        current_window = 1;
                    }
                    else if (point_in_circle(mx, my, 30, ydot2, 10))
                    {
                        current_window = 2;
                    }
                    else if (point_in_circle(mx, my, 30, ydot3, 10))
                    {
                        current_window = 3;
                    }
                    else if (point_in_circle(mx, my, 30, ydot4, 10))
                    {
                        current_window = 4;
                    }
                    else if (point_in_circle(mx, my, 30, ydot5, 10))
                    {
                        current_window = 5;
                    }
                }
            }
            else if (current_window == 1)
            {
                for (int i = 0; i < CLUBS; i++)
                {
                    int ydot = 110 + i * 44;
                    int ytxt = 104 + i * 44;
                    fill_circle(color_aqua(), 30, ydot, 10);
                    draw_text(clubs_options[i], color_black(), 60, ytxt);
                }
                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 0;
                }
                if (mouse_clicked(LEFT_BUTTON))
                {
                    int mx = mouse_x(), my = mouse_y();
                    for (int i = 0; i < CLUBS; i++)
                    {
                        int ydot = 110 + i * 44;
                        if (point_in_circle(mx, my, 30, ydot, 10))
                        {
                            current_window = 6 + i;
                        }
                    }
                }
            }
            else if (current_window >= 6 && current_window <= 9)
            {
                int ci = current_window - 6;
                draw_rectangle(color_black(), 24, 88, 200, 180);
                draw_rectangle(color_black(), 296, 88, 200, 180);
                {
                    player &pl = clubs[ci].get_player_ref(0);
                    string pname = pl.get_name(pl);
                    int pgoals = pl.get_goals(pl);
                    draw_text(pname, color_black(), 32, 96);
                    draw_text(clubs[ci].get_name(clubs[ci]), color_black(), 32, 118);
                    draw_text("Goals: " + std::to_string(pgoals), color_black(), 32, 140);
                }
                {
                    player &pl = clubs[ci].get_player_ref(1);
                    string pname = pl.get_name(pl);
                    int pgoals = pl.get_goals(pl);
                    draw_text(pname, color_black(), 304, 96);
                    draw_text(clubs[ci].get_name(clubs[ci]), color_black(), 304, 118);
                    draw_text("Goals: " + std::to_string(pgoals), color_black(), 304, 140);
                }
                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 1;
                }
            }
            else if (current_window == 2)
            {
                int y = 88;
                for (int i = 0; i < fixture_count; i++)
                {
                    string home_name = clubs[home[i]].get_name(clubs[home[i]]);
                    string away_name = clubs[away[i]].get_name(clubs[away[i]]);
                    string line;
                    line = std::to_string(i + 1) + ". " + home_name + " vs " + away_name;
                    draw_text(line, color_black(), 24, y);
                    y += 24;
                }
                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 0;
                }
            }
            else if (current_window == 3)
            {
                int y = 88;
                for (int i = 0; i < fixture_count; i++)
                {
                    if (!played_flag[i])
                    {
                        continue;
                    }
                    string home_name = clubs[home[i]].get_name(clubs[home[i]]);
                    string away_name = clubs[away[i]].get_name(clubs[away[i]]);
                    string line = std::to_string(i + 1) + ". " + home_name + " " + std::to_string(m_home_goals[i]) + " - " + std::to_string(m_away_goals[i]) + " " + away_name;
                    draw_text(line, color_black(), 24, y);
                    y += 24;
                }
                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 0;
                }
            }
            else if (current_window == 4)
            {
                int order[CLUBS];
                sort_table(order);

                const int X_POS = 24;
                const int X_CLUB = 80;
                const int X_P = 220;
                const int X_W = 260;
                const int X_D = 300;
                const int X_L = 340;
                const int X_GF = 380;
                const int X_GA = 420;
                const int X_GD = 460;
                const int X_PTS = 500;

                int y = 88;

                draw_text("Pos", color_black(), X_POS, y);
                draw_text("Club", color_black(), X_CLUB, y);
                draw_text("P", color_black(), X_P, y);
                draw_text("W", color_black(), X_W, y);
                draw_text("D", color_black(), X_D, y);
                draw_text("L", color_black(), X_L, y);
                draw_text("GF", color_black(), X_GF, y);
                draw_text("GA", color_black(), X_GA, y);
                draw_text("GD", color_black(), X_GD, y);
                draw_text("Pts", color_black(), X_PTS, y);
                y += 28;

                for (int pos = 0; pos < CLUBS; pos++)
                {
                    int i = order[pos];
                    int gdv = gd(i, gf, ga);
                    int pts = points(i, won, drawn);

                    draw_text(std::to_string(pos + 1) + ".", color_black(), X_POS, y);

                    draw_text(clubs[i].get_name(clubs[i]), color_black(), X_CLUB, y);

                    draw_text(std::to_string(played[i]), color_black(), X_P, y);
                    draw_text(std::to_string(won[i]), color_black(), X_W, y);
                    draw_text(std::to_string(drawn[i]), color_black(), X_D, y);
                    draw_text(std::to_string(lost[i]), color_black(), X_L, y);
                    draw_text(std::to_string(gf[i]), color_black(), X_GF, y);
                    draw_text(std::to_string(ga[i]), color_black(), X_GA, y);
                    draw_text(std::to_string(gdv), color_black(), X_GD, y);
                    draw_text(std::to_string(pts), color_black(), X_PTS, y);

                    y += 24;
                }

                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 0;
                }
            }
            else if (current_window == 5)
            {
                string pname[CLUBS * PLAYERS_PER_CLUB];
                string cname[CLUBS * PLAYERS_PER_CLUB];
                int goals[CLUBS * PLAYERS_PER_CLUB];
                int n = 0;

                for (int c = 0; c < CLUBS; c++)
                {
                    for (int p = 0; p < PLAYERS_PER_CLUB; p++)
                    {
                        pname[n] = clubs[c].get_player_ref(p).get_name(clubs[c].get_player_ref(p));
                        cname[n] = clubs[c].get_name(clubs[c]);
                        goals[n] = clubs[c].get_player_ref(p).get_goals(clubs[c].get_player_ref(p));
                        n++;
                    }
                }
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = 0; j < n - 1 - i; j++)
                    {
                        bool swap_needed = false;
                        if (goals[j] < goals[j + 1])
                        {
                            swap_needed = true;
                        }
                        else if (goals[j] == goals[j + 1])
                        {
                            if (cname[j] > cname[j + 1])
                            {
                                swap_needed = true;
                            }
                            else if (cname[j] == cname[j + 1])
                            {
                                if (pname[j] > pname[j + 1])
                                {
                                    swap_needed = true;
                                }
                            }
                        }
                        if (swap_needed)
                        {
                            int tg = goals[j];
                            goals[j] = goals[j + 1];
                            goals[j + 1] = tg;
                            string tn = pname[j];
                            pname[j] = pname[j + 1];
                            pname[j + 1] = tn;
                            string tc = cname[j];
                            cname[j] = cname[j + 1];
                            cname[j + 1] = tc;
                        }
                    }
                }

                const int X_RANK = 24;
                const int X_PLAYER = 60;
                const int X_CLUB = 240;
                const int X_GOALS = 400;

                int y = 88;

                draw_text("Rank", color_black(), X_RANK, y);
                draw_text("Player", color_black(), X_PLAYER, y);
                draw_text("Club", color_black(), X_CLUB, y);
                draw_text("Goals", color_black(), X_GOALS, y);
                y += 28;

                for (int i = 0; i < n; i++)
                {
                    draw_text(std::to_string(i + 1), color_black(), X_RANK, y);
                    draw_text(pname[i], color_black(), X_PLAYER, y);
                    draw_text(cname[i], color_black(), X_CLUB, y);
                    draw_text(std::to_string(goals[i]), color_black(), X_GOALS, y);
                    y += 24;
                }

                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 540, 540, 60))
                {
                    current_window = 0;
                }
            }
            refresh_screen(90);
        }
    }
    void run()
    {
        build_fixtures();

        write_line("");
        write_line("===== Fixtures =====");
        for (int i = 0; i < fixture_count; i++)
        {
            write_line(std::to_string(i + 1) + ". " + clubs[home[i]].get_name(clubs[home[i]]) + " vs " + clubs[away[i]].get_name(clubs[away[i]]));
        }

        write_line("");
        write_line("===== Play Matches =====");
        for (int i = 0; i < fixture_count; i++)
        {
            write_line("");
            write_line("Match " + std::to_string(i + 1) + " of " + std::to_string(fixture_count) + ": " + clubs[home[i]].get_name(clubs[home[i]]) + " vs " + clubs[away[i]].get_name(clubs[away[i]]));

            int hg = input_goals_for_club(home[i]);
            int ag = input_goals_for_club(away[i]);

            m_home_goals[i] = hg;
            m_away_goals[i] = ag;
            played_flag[i] = true;

            update_table(home[i], away[i], hg, ag);

            write_line("Result: " + clubs[home[i]].get_name(clubs[home[i]]) + " " + std::to_string(hg) + " - " + std::to_string(ag) + " " + clubs[away[i]].get_name(clubs[away[i]]));

            print_table();
        }

        write_line("");
        write_line("===== Final Table =====");
        print_table();

        write_line("");
        write_line("===== Top Scorers =====");
        print_top_scorers();
    }
};

class AuthManager
{
private:
    string usernames[MAX_USERS];
    string passwords[MAX_USERS];
    int count = 0;
    bool signed_in = false;
    string who;

public:
    int find_user(const string &u)
    {
        for (int i = 0; i < count; i++)
        {
            if (usernames[i] == u)
            {
                return i;
            }
        }
        return -1;
    }
    bool is_signed_in()
    {
        return signed_in;
    }
    string current_user()
    {
        return who;
    }
    bool signup()
    {
        write_line("=== Create Account ===");
        write("Username: ");
        string u = read_line();
        if (u == "")
        {
            write_line("Username cannot be empty.");
            return false;
        }
        if (find_user(u) != -1)
        {
            write_line("That username already exists.");
            return false;
        }
        if (count >= MAX_USERS)
        {
            write_line("User limit reached.");
            return false;
        }
        write("Password: ");
        string p = read_line();
        if (p == "")
        {
            write_line("Password cannot be empty.");
            return false;
        }
        usernames[count] = u;
        passwords[count] = p;
        count++;
        write_line("Account created. You can sign in now.");
        return true;
    }
    bool signin()
    {
        write_line("=== Sign In ===");
        write("Username: ");
        string u = read_line();
        write("Password: ");
        string p = read_line();

        int idx = find_user(u);
        if (idx == -1 || passwords[idx] != p)
        {
            write_line("Invalid username or password.");
            return false;
        }
        signed_in = true;
        who = u;
        write_line("Signed in as " + who + ".");
        return true;
    }
    bool auth_ui(AuthManager &auth)
    {
        string title = "Account";
        open_window(title, 420, 360);

        int screen = 0;

        while (!quit_requested())
        {
            process_events();
            clear_screen(color_white());
            fill_rectangle(color_black(), 0, 0, 420, 60);
            draw_text("Account Setup", color_white(), 18, 20);

            if (screen == 0)
            {
                int y1 = 110, y2 = 154, y3 = 198;
                fill_circle(color_aqua(), 30, y1, 10);
                fill_circle(color_aqua(), 30, y2, 10);
                fill_circle(color_aqua(), 30, y3, 10);
                draw_text("1. Sign In", color_black(), 60, y1 - 6);
                draw_text("2. Create Account", color_black(), 60, y2 - 6);
                draw_text("3. Quit", color_black(), 60, y3 - 6);

                if (mouse_clicked(LEFT_BUTTON))
                {
                    int mx = mouse_x(), my = mouse_y();
                    if (point_in_circle(mx, my, 30, y1, 10))
                    {
                        if (auth.signin())
                        {
                            screen = 1;
                        }
                    }
                    else if (point_in_circle(mx, my, 30, y2, 10))
                    {
                        auth.signup();
                    }
                    else if (point_in_circle(mx, my, 30, y3, 10))
                    {
                        close_window(title);
                        return auth.is_signed_in();
                    }
                }
            }
            else if (screen == 1)
            {
                draw_text("Welcome, " + auth.current_user(), color_black(), 24, 110);
                draw_text("Click <Continue> to continue", color_black(), 24, 140);

                fill_rectangle(color_black(), 0, 300, 420, 60);
                draw_text("Continue", color_white(), 18, 320);

                if (mouse_clicked(LEFT_BUTTON) && point_in_rectangle(mouse_x(), mouse_y(), 0, 300, 420, 60))
                {
                    close_window(title);
                    return true;
                }
            }

            refresh_screen(90);
        }
        close_window(title);
        return auth.is_signed_in();
    }
};

int main()
{
    AuthManager auth;
    if (!auth.auth_ui(auth)) // The program ends when users cannot sign in
    {
        return 0;
    }
    championship league;
    club c1, c2, c3, c4;
    league.add_club(c1, c2, c3, c4, league);
    league.run();
    league.user_interface(league);
    return 0;
}