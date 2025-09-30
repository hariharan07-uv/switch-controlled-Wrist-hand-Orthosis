#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// Replace with your Wi-Fi credentials
const char* ssid = "Hax";
const char* password = "123456789";

// Create server on port 80
WebServer server(80);

// Define servos
Servo wristServo;
Servo thumbServo;
Servo indexServo;
Servo fingersServo;

// Servo GPIO pins
#define WRIST_PIN   19
#define THUMB_PIN   18
#define INDEX_PIN   26
#define FINGERS_PIN 27

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  // Attach servos
  wristServo.attach(WRIST_PIN);
  thumbServo.attach(THUMB_PIN);
  indexServo.attach(INDEX_PIN);
  fingersServo.attach(FINGERS_PIN);

  // Web server routes
  server.on("/", handleRoot);
  server.on("/set", handleSetServo);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 Hand Control</title>
      <style>
        body { font-family: sans-serif; text-align: center; }
        .slider { width: 80%; margin: 20px auto; }
      </style>
    </head>
    <body>
      <h2>ESP32 Robotic Hand Controller</h2>

      <div class="slider">
        <label>Wrist</label><br>
        <input type="range" min="0" max="360" value="90" id="wrist" oninput="updateServo('wrist', this.value)">
      </div>

      <div class="slider">
        <label>Thumb</label><br>
        <input type="range" min="0" max="360" value="0" id="thumb" oninput="updateServo('thumb', this.value)">
      </div>

      <div class="slider">
        <label>Index</label><br>
        <input type="range" min="0" max="360" value="0" id="index" oninput="updateServo('index', this.value)">
      </div>

      <div class="slider">
        <label>Fingers</label><br>
        <input type="range" min="0" max="360" value="0" id="fingers" oninput="updateServo('fingers', this.value)">
      </div>

      <script>
        function updateServo(servo, angle) {
          fetch(`/set?servo=${servo}&angle=${angle}`);
        }
      </script>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleSetServo() {
  if (!server.hasArg("servo") || !server.hasArg("angle")) {
    server.send(400, "text/plain", "Missing parameters");
    return;
  }

  String servoName = server.arg("servo");
  int angle = server.arg("angle").toInt();
  angle = constrain(angle, 0, 550);

  if (servoName == "wrist")       wristServo.write(angle);
  else if (servoName == "thumb")  thumbServo.write(angle);
  else if (servoName == "index")  indexServo.write(angle);
  else if (servoName == "fingers") fingersServo.write(angle);
  else {
    server.send(400, "text/plain", "Invalid servo");
    return;
  }
  
  server.send(200, "text/plain", "OK");
}