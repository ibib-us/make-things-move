#pragma once

void init_everything();
void update();
void driveForward(bool pressed);
void driveBackward(bool pressed);
void steerRight(bool pressed);
void steerLeft(bool pressed);

void incDuty(bool pressed);
void decDuty(bool pressed);