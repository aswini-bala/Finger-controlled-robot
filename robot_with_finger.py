import cv2
import serial
import mediapipe as mp

# Initialize MediaPipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()

# Initialize your webcam or other video sources
cap = cv2.VideoCapture(0)

# Serial communication setup
serial_port = 'COM10'  # Replace with your Arduino's serial port
baud_rate = 9600
arduino = serial.Serial(serial_port, baud_rate, timeout=1)

while True:
    ret, frame = cap.read()
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    results = hands.process(frame_rgb)

    finger_count = 0

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            tip_ids = [4, 8, 12, 16, 20]  # Tip landmarks for each finger
            fingers = [1 if hand_landmarks.landmark[i].y < hand_landmarks.landmark[i-2].y else 0 for i in tip_ids]
            finger_count = sum(fingers)
            finger_count = finger_count-1
            print(finger_count)
    # Send the finger count to the Arduino
    arduino.write(str(finger_count).encode())

    cv2.putText(frame, f'Finger Count: {finger_count}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    cv2.imshow('Finger Count', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
