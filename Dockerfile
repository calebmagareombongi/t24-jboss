# Use official WildFly (JBoss) base image
FROM quay.io/wildfly/wildfly:latest

# Switch to root user to allow permission changes
USER root

# Copy your entire JBoss setup into the container
COPY . /opt/jboss/wildfly/

# Fix file permissions for the startup script
RUN chmod +x /opt/jboss/wildfly/bin/standalone.sh

# Switch back to the default JBoss user for security
USER jboss

# Set the working directory
WORKDIR /opt/jboss/wildfly

# Limit Java memory (important for free tiers)
ENV JAVA_OPTS="-Xms256m -Xmx768m"

# Expose the default port
EXPOSE 8080

# Start WildFly and bind to external port (Render sets PORT automatically)
CMD ["sh", "-c", "/opt/jboss/wildfly/bin/standalone.sh -b 0.0.0.0 -Djboss.http.port=${PORT:-8080}"]
