//This is PROGRAM FOR RELAY BASED BULB ON & OFF
//PHASE/LINE CONNECTED TO RELAY'S COMMON, ONE END WIRE FROM BULB CONNECTED TO NC
//AND OTHER WIRE OF BULB CONNECTED ON NEUTRAL
//wifi detection on mobile and using chrome webbrowser giving command wifi ip add->192.168.4.1/lon for RELAY on
//and 192.168.4.1/loff for RELAY-off
//feedback from relay chatter display on and off................

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "IOT_SSD_CNT"; //WIFI NAME APPEARS ON MOBILE
const char* password = "123456789"; //TYPE PASS IN MOBILE
ESP8266WebServer server(80);  // SERVER FREQENCY
const char getPage[] PROGMEM = {"<!DOCTYPE html>\n<html>\n<head>\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<style>\nbody{\nbackground-color:#e6ccff;\ntext-align: center;\n}\n    \nh1 {\n\n    font-family:arial;\n    font-size: 30px;\n    color:#cc0000;\n    text-align: center;\n    text-shadow: 0 1.4px #000033;\n}\nfooter {\n      font-family:arial;\n      font-size: 19px;\n      color:darkblue;\n      text-align: center;\n      padding: 70px;\n   }\n\n.button {\n    background-color: #3e8e41;\n    border: none;\n    color: white;\n    padding: 17px;\n    text-align: center;\n    text-decoration: none;\n    display: inline-block;\n    font-size: 19px;\n    margin: 6px 3px;\n    cursor: pointer;\n    box-shadow: 0 5px #666;\n}\n\n.button:hover {background-color: #ff9800}\n\n.active{\n  background-color: #3e8e41;\n  box-shadow: 0 5px #666;\n  transform: translateY(9px);\n}\n\n.button1 {border-radius: 9px;}\n \nfooter {-webkit-order:3;order:3;}\n</style>\n</head>\n<body>\n<h1 align=\"center\">IOT based device control using web browser</h1>\n<div id=\"myDIV\" align=\"center\">\n<a href=\\/192.168.4.1/01><input type=\"button\" id=\"b1\" class=\"button button1\"  onclick=\"fnb_1()\" value=\"1\" name='LED' value='1'></a>\n<a href=\\/192.168.4.1/02><input type=\"button\" id=\"b2\" class=\"button button1\"  onclick=\"fnb_2()\" value=\"2\" name='LED' value='2'></a>\n<a href=\\/192.168.4.1/03><input type=\"button\" id=\"b3\" class=\"button button1\"  onclick=\"fnb_3()\" value=\"3\" name='LED' value='3'></a>\n<a href=\\/192.168.4.1/04><input type=\"button\" id=\"b4\" class=\"button button1\"  onclick=\"fnb_4()\" value=\"4\" name='LED' value='4'></a>\n<a href=\\/192.168.4.1/05><input type=\"button\" id=\"b5\" class=\"button button1\"  onclick=\"fnb_5()\" value=\"5\" name='LED' value='5'></a>\n<a href=\\/192.168.4.1/06><input type=\"button\" id=\"b6\" class=\"button button1\"  onclick=\"fnb_6()\" value=\"6\" name='LED' value='6'></a>\n<a href=\\/192.168.4.1/07><input type=\"button\" id=\"b7\" class=\"button button1\"  onclick=\"fnb_7()\" value=\"7\" name='LED' value='7'></a>\n<a href=\\/192.168.4.1/08><input type=\"button\" id=\"b8\" class=\"button button1\"  onclick=\"fnb_8()\" value=\"8\" name='LED' value='8'></a>\n</div>\n\n<script>\nfunction fnb_1() {\n localStorage.button_no = 1;}\nfunction fnb_2() {\n localStorage.button_no = 2;}\nfunction fnb_3() {\n localStorage.button_no = 3;}\nfunction fnb_4() {\n localStorage.button_no = 4;}\nfunction fnb_5() {\n localStorage.button_no = 5;}\nfunction fnb_6() {\n localStorage.button_no = 6;}\nfunction fnb_7() {\n localStorage.button_no = 7;}\nfunction fnb_8() {\n localStorage.button_no = 8;}\n \nswitch(){ \nfunction fnb1() {\nLED = document.getElementById(\"b1\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb2() {\nLED = document.getElementById(\"b2\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb3() {\nLED = document.getElementById(\"b3\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb4() {\nLED = document.getElementById(\"b4\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb5() {\nLED = document.getElementById(\"b5\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb6() {\nLED = document.getElementById(\"b6\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb7() {\nLED = document.getElementById(\"b7\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\nfunction fnb8() {\nLED = document.getElementById(\"b7\").value;\ncurrent[0].className = current[0].className.replace(\" active\", \"\");\nthis.className += \" active\";\n}\n</script>\n\n<footer><p><b><strong>PROLIFIC SYSTEMS AND TECHNOLIGIES PVT. LTD. </strong></b></p></footer >\n\n</body>\n</html>\n"};

void handleRoot()
{
  server.send_P( 200, "text/html", getPage);
}

void handle01()
{
  digitalWrite(14, 0); //d5
  digitalWrite(12, 0); //d6
  digitalWrite(13, 0); //d7
  digitalWrite(16, 0); //d0
  handleRoot();
  delay(5);
}

void handle02()
{
  digitalWrite(14, 1);
  digitalWrite(12, 0);

  
  digitalWrite(13, 0);
  digitalWrite(16, 1);
 
  handleRoot();
  delay(5);
}

void handle03()
{
  digitalWrite(14, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 0);
  digitalWrite(5, 1); //d1
  handleRoot();
  delay(5);
}

void handle04()
{
  digitalWrite(14, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 0);
  digitalWrite(5, 0);
  handleRoot();
  delay(5);
}

void handle05()
{
  digitalWrite(14, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 1);//4th
  handleRoot();
  delay(5);
}

void handle06()
{
  digitalWrite(14, 1);
  digitalWrite(12, 0);
  digitalWrite(13, 1);
  handleRoot();
  delay(5);
}

void handle07()
{
  digitalWrite(14, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  handleRoot();
  delay(5);
}

void handle08()
{
  digitalWrite(14, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  handleRoot();
  delay(5);
}

void setup(void)
{
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(14, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 0);
  digitalWrite(16, 0);
  digitalWrite(5, 0);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password); //GENERATE PASSWORD AND USER NAME
  IPAddress myIP = WiFi.softAPIP();//GENERTION OF IP ADD FROM SERIAL COMMU..
  Serial.print("AP IP address: ");
  Serial.println(myIP); //PRINTF IP ADD
  server.on("/", handleRoot);
  server.on("/01", handle01);
  server.on("/02", handle02);
  server.on("/03", handle03);
  server.on("/04", handle04);
  server.on("/05", handle05);
  server.on("/06", handle06);
  server.on("/07", handle07);
  server.on("/08", handle08);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
}


