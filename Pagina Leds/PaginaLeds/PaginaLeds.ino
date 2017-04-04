#include <ESP8266WiFi.h>
#define LED 02

const char* ssid = "Red";
const char* password = "";
IPAddress ip(192,168,1,222);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
int Delay = 1000;
WiFiServer Servidor(80);

void setup() {
    Serial.begin(115200);
    delay(10);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    WiFi.begin(ssid, password);
    WiFi.config(ip, gateway, subnet);
    Servidor.begin(); 
}

void loop() {

    digitalWrite(LED,LOW);
    delay(Delay);
    digitalWrite(LED,HIGH);
    delay(Delay);
    WiFiClient Cliente = Servidor.available();
    if( !Cliente ) return;

    Serial.println("Nuevo Cliente encontrado");
    while(!Cliente.available()) delay(1);    
    String resp = Cliente.readStringUntil('\r');
    Cliente.flush();
    int valor = digitalRead(LED);

    if(resp.indexOf("/LED=D") != -1){
        Delay = Delay - 100; 
    }
    if(resp.indexOf("/LED=A") != -1){
        Delay = Delay + 100; 
    }

    Cliente.println("HTTP/1.1 200 OK");
    Cliente.println("Content-Type: text/html");
    Cliente.println("");
    Cliente.println("<!DOCTYPE HTML>");
    Cliente.println("<html>");
    Cliente.println("Parpadeo: ");
    Cliente.println("<a href=\"/LED=A\"\"><button>Aumentar</button></a><br />");  
    Cliente.println("<a href=\"/LED=D\"\"><button>Disminuir</button></a>"); 
    Cliente.println("</html>"); 
    
    
    delay(1);
}
