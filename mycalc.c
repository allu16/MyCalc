#include "raylib.h"

#define BUTTONS_AMOUNT 20
#define BUTTONS_COLUMNS 4
#define BUTTONS_ROWS 5

#define BUTTON_WIDTH 150
#define BUTTON_HEIGHT 150

#define BUTTON_GAP 5

#define FONT_SIZE 50

const char button_characters[BUTTONS_AMOUNT] = {' ', 'C', 'B', 'D', '7', '8', '9', 'X', '4', '5', '6', '-', '1', '2', '3', '+', ' ', '0', '.', '='}; 

typedef struct {
    Rectangle rectangle;
    char character;
} Button;

int InitButtons(Button* buttons, int columns, int rows) {
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            int pos_x = 50 + (BUTTON_WIDTH + BUTTON_GAP) * j;
            int pos_y = 100 + (BUTTON_HEIGHT + BUTTON_GAP) * i;
            Button new_button = {{pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT}, button_characters[k]};
            buttons[k] = new_button;
            k++;
        }
    }

    return 0;
}

int DrawAllButtons(Button* buttons, int amount) {
    for(int i = 0; i < amount; i++) {
        DrawRectangleRec(buttons[i].rectangle, WHITE);
        DrawText(&buttons[i].character,
            buttons[i].rectangle.x + BUTTON_WIDTH / 3,
            buttons[i].rectangle.y + BUTTON_HEIGHT / 3,
            FONT_SIZE, DARKGRAY
        );
    }

    return 0;
}

int main() {
    const int width = 800;
    const int height = 1000;
    const char* title = "MyCalc";

    Button buttons[BUTTONS_AMOUNT];

    InitButtons(buttons, BUTTONS_COLUMNS, BUTTONS_ROWS);

    InitWindow(width, height, title);

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        for(int i = 0; i < BUTTONS_AMOUNT; i++) {
            if(!CheckCollisionPointRec(GetMousePosition(), buttons[i].rectangle)) continue;
            if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) continue;

        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawAllButtons(buttons, BUTTONS_AMOUNT);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}