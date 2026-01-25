#include "../src/at_ray.h"
#include "acoustic/at_math.h"

#include <stdio.h>

#include "../external/raylib.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

int main()
{
    printf("ray init!\n");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ray test");

    AT_Ray ray = AT_ray_init(
        (AT_Vec3){0, 0, 0},
        (AT_Vec3){1, 0, 0},
        0
    );

    SetTargetFPS(60);

    Camera3D cam = {0};
    cam.position = (Vector3){ 0.0, 1.0, 2.0 };
    cam.target = (Vector3){ 1.0, 0.5, 0.0 };
    cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam.fovy = 60.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {

        UpdateCamera(&cam, CAMERA_FREE);

        BeginDrawing();
        {
            ClearBackground(BLACK);
            BeginMode3D(cam);
            {
                DrawRay((Ray){
                    (Vector3){ray.origin.x, ray.origin.y, ray.origin.z},
                    (Vector3){ray.direction.x, ray.direction.y, ray.direction.z}},
                    RED);
            }
            EndMode3D();
        }
        EndDrawing();
    }

    return 0;
}
