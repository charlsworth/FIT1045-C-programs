// File Name: badcode.cpp
// Author Name: Charlie Cowled
// Creation Date: 24/03/2026
// Version: v1

// Global/Libraries
#include <splashkit.h>

// Functions

// returns true is spider is in bounds
bool in_bounds(int spiderX, int spiderY, int spiderRadius, int screenHeight, int screenWidth)
{
    return (spiderX - spiderRadius >= 0 && spiderX + spiderRadius <= screenWidth && spiderY - spiderRadius >= 0 && spiderY + spiderRadius <= screenHeight);
}

// moves spider based on keyboard inputs
void move_spider(int &spiderX, int &spiderY, int spiderSpeed, int spiderRadius, int screenHeight, int screenWidth)
{
    int dx = 0; // change in x position
    int dy = 0; // change in y position

    if (key_down(UP_KEY))
        dy--;
    if (key_down(DOWN_KEY))
        dy++;
    if (key_down(LEFT_KEY))
        dx--;
    if (key_down(RIGHT_KEY))
        dx++;

    int tempX = spiderX + dx * spiderSpeed;
    int tempY = spiderY + dy * spiderSpeed;

    // save new position if it is in bounds
    if (in_bounds(tempX, tempY, spiderRadius, screenHeight, screenWidth))
    {
        spiderX = tempX;
        spiderY = tempY;
    }
}

// returns true if spider and fly colide
bool collision(int spiderX, int spiderY, int spiderRadius, int flyX, int flyY, int flyRadius)
{
    int dx = spiderX - flyX;
    int dy = spiderY - flyY;
    int distanceSum = dx * dx + dy * dy;
    int radiusSum = flyRadius + spiderRadius;
    return (distanceSum <= radiusSum * radiusSum);
}

// positions fly at random location within the bounds of the windpow
void create_fly(int &flyX, int &flyY, int flyRadius, int screenHeight, int screenWidth, bool &flyAppeared, string gameTimer)
{
    static long appearAtTime = 0;

    // create a spawn delay on first instance
    if (appearAtTime == 0)
    {
        appearAtTime = 500 + rnd(1000);
    }

    // spawn fly after delay
    if (!flyAppeared && timer_ticks(gameTimer) > appearAtTime)
    {
        flyX = rnd(flyRadius, screenWidth - flyRadius);
        flyY = rnd(flyRadius, screenHeight - flyRadius);
        flyAppeared = true;
        appearAtTime = 500 + rnd(1000);
    }

    // draw fly
    if (flyAppeared)
    {
        fill_circle(COLOR_GREEN, flyX, flyY, flyRadius);
    }
}

int main()
{

    int screenWidth = 800;
    int screenHeight = 600;

    int spiderX = screenWidth / 2;
    int spiderY = screenHeight / 2;
    int spiderRadius = 40;
    int spiderSpeed = 4;

    int flyRadius = 20;
    int flyX = 0;
    int flyY = 0;

    int catchNumber = 0;
    bool flyAppeared = false;
    string gameTimer = "GameTimer";

    open_window("Fly Catch", screenWidth, screenHeight);
    create_timer(gameTimer);
    start_timer(gameTimer);

    while (!quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        move_spider(spiderX, spiderY, spiderSpeed, spiderRadius, screenHeight, screenWidth);
        fill_circle(color_black(), spiderX, spiderY, spiderRadius);
        create_fly(flyX, flyY, flyRadius, screenHeight, screenWidth, flyAppeared, gameTimer);

        // resets timer and creates new fly after fly is caught
        if (collision(spiderX, spiderY, spiderRadius, flyX, flyY, flyRadius))
        {
            flyAppeared = false;
            catchNumber++;
            flyX = 0;
            flyY = 0;
            write_line("You caught the Fly " + to_string(catchNumber) + " times!");
            reset_timer(gameTimer);
        }
        refresh_screen(60);
    }
    return 0;
}
