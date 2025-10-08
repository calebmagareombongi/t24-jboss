@echo off
TITLE (JBoss 6.4 GA) : Port 8085

set JAVA_HOME=C:\R20\jdk1.8.0_211
echo "JAVA_HOME is : %JAVA_HOME%"

set TAFJ_HOME=C:\R20\TAFJ
rem echo "TAFJ_HOME is : %TAFJ_HOME%"

set JBOSS_HOME=C:\R20\jboss-eap-7.2
echo "JBOSS_HOME is : %JBOSS_HOME%"

set PATH=%JAVA_HOME%\bin;%TAFJ_HOME%\bin;%PATH%;%JBOSS_HOME%\bin

cd %JBOSS_HOME%\bin
@echo off
set "JAVA_OPTS=-Xms256m -Xmx128m"

CALL standalone.bat --server-config=standalone.xml -b 0.0.0.0 -Djboss.server.base.dir=C:\R20\jboss-eap-7.2\standalone -Dhostname=OSOFUNDE-FBU
