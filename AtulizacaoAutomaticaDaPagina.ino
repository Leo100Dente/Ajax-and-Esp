#include <WiFi.h>
#include <WebServer.h>
// Feito para o uso de todos aqueles que são dignos de usar kkk
// Feito por Leonardo da Familia Happy Boys

WebServer server(80);

const char *ssid = "***"; // O nome da sua rede WiFi
const char *passwd = "***"; // Senha da Sua rede WiFi

int i = 0;

void handleRoot()
{
  server.send(200, "text/html", "<h1>Hello! FHP(Familia Happy Boys)</h1>");
}
void handleTest()
{
  i++;
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plan", String(i));
}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, passwd);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado a rede WiFi!");
  Serial.print("O IP do ESP é: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/test", handleTest);
  server.begin();
  Serial.println("Servidor Iniciado com Sucesso!!");
}

void loop()
{
  server.handleClient();
  delay(1);
}
