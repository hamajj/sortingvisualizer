#include <raylib.h>
#include <stdio.h>
#include "sort.h"

#define WIDTH 800
#define HEIGHT 600

int main(void)
{
        InitWindow(WIDTH, HEIGHT, "sorting algorithm visualizer");

        SetTargetFPS(60);

        int size = 20;
        int i = 0, j = 0;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
                arr[i] = GetRandomValue(10, HEIGHT - 10);
        }

        // Main game loop
        while (!WindowShouldClose())
        {
                BeginDrawing();

                ClearBackground(RAYWHITE);
                //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

                for (int k = 0; k < size; k++) {
                        if (k == j)
                                DrawRectangle(k * 40 + 10, HEIGHT - arr[k], 30, arr[k], RED);
                        else if (k == j + 1)
                                DrawRectangle(k * 40 + 10, HEIGHT - arr[k], 30, arr[k], GREEN); 
                        else
                                DrawRectangle(k * 40 + 10, HEIGHT - arr[k], 30, arr[k], BLUE);
                }

                if( isSorted(arr, size)) {
                        DrawText("Array is sorted! Press UP to randomize.", 10, 10, 20, DARKGREEN);
                } else {
                        DrawText("Press SPACE to perform a bubble sort step.", 10, 10, 20, DARKGRAY);
                        DrawText("Press UP to randomize the array.", 10, 40, 20, DARKGRAY);
                }
                
                if ((IsKeyPressed(KEY_SPACE)))
                {
                        bubble_sort_step(arr, size, &i, &j);
                }
                if (IsKeyPressed(KEY_UP)) {
                        for (int k = 0; k < size; k++) {
                                arr[k] = GetRandomValue(10, HEIGHT - 10);
                        }
                        i = j = 0;
                }
                EndDrawing();
        }
        CloseWindow();
        return 0;
}