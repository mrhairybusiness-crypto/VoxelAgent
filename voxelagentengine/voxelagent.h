#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "rlgl.h"

Rectangle CreateRectangle(float Width, float  Height, float PositionX, float PositionY) {
    Rectangle rect = { PositionX, PositionY, Width, Height };
    return rect;
}

Color Create_Color(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) {
    Color RGB_COLOR = { Red, Green, Blue, Alpha};
    return RGB_COLOR;
}

void DrawRoundRectangle(Rectangle Created_Rectangle, float Roundness, Color RGB_Color) {
    DrawRectangleRounded(Created_Rectangle, Roundness, 32, RGB_Color);
}

void DrawNewRectangle(float Width, float Height, float PositionX, float PositionY, Color RGB_Color) {
    DrawRectangle(PositionX, PositionY, Width, Height, RGB_Color);
}

void DrawRoundedLines(float Width, float Height, float PositionX, float PositionY, float Roundness, Color RGB_Color) {
    DrawRectangleRoundedLines((Rectangle){PositionX, PositionY, Width, Height}, Roundness, 32, RGB_Color);
}

void DrawLines(float Width, float Height, float PositionX, float PositionY, Color RGB_Color) {
    DrawRectangleLines(PositionX, PositionY, Width, Height, RGB_Color);
}

void SetBackgroundColor(Color RGB_Color) {
    ClearBackground(RGB_Color);
}

void CreateWindow(float Width, float Height, const char* title_text) {
    InitWindow(Width, Height, title_text);
};

void SetFPSTo(float FPS) {
    SetTargetFPS(FPS);
}

void StartDrawing() {
    BeginDrawing();
}

void StopDrawing() {
    EndDrawing();
}

void DrawNewCircle(float WidthAndHeightOrRadius, float PositionX, float PositionY, Color RGB_Color) {
    DrawCircle(PositionX, PositionY, WidthAndHeightOrRadius, RGB_Color);
}

void DrawNewText(const char* Text, float PositionX, float PositionY, float Text_Size, Color RGB_Color) {
    DrawText(Text, PositionX, PositionY, Text_Size, RGB_Color);
};

// 3D

Camera3D CreateACamera(float PositionX, float PositionY, float PositionZ, float RotationX, float RotationY, float RotationZ, float Field_Of_View_Or_FOV) {
    Camera3D cam = { 0 };
    cam.position = (Vector3){PositionX, PositionY, PositionZ};
    cam.target = (Vector3){RotationX, RotationY, RotationZ};
    cam.up = (Vector3){0.0f, 1.0f, 0.0f};
    cam.fovy = Field_Of_View_Or_FOV;
    cam.projection = CAMERA_PERSPECTIVE;

    return cam;
}

void StartDrawingIn3D(Camera3D CameraFromCreateACamera) {
    BeginMode3D(CameraFromCreateACamera);
}

void StopDrawingIn3D() {
    EndMode3D();
}

void Draw3DCube(float PositionX, float PositionY, float PositionZ, float RotationX, float RotationY, float RotationZ, float Width, float Height, float Depth, Color RGB_Color) {
   rlPushMatrix();
   rlTranslatef(PositionX, PositionY, PositionZ);
   rlRotatef(RotationX, 1.0f, 0.0f, 0.0f);
   rlRotatef(RotationY, 0.0f, 1.0f, 0.0f);
   rlRotatef(RotationZ, 0.0f, 0.0f, 1.0f);
   DrawCube((Vector3){0, 0, 0}, Width, Height, Depth, RGB_Color);
   rlPopMatrix();
}

void Draw3DSphere(float PositionX, float PositionY, float PositionZ, float Radius, Color RGB_Color) {
    DrawSphere((Vector3){PositionX, PositionY, PositionZ}, Radius, RGB_Color);
}
