# Use official WildFly (JBoss) base image
FROM quay.io/wildfly/wildfly:latest

# Switch to root to set permissions if needed
USER root

# Copy WAR file(s) into WildFly deployments folder
COPY *.war /opt/jboss/wildfly/standalone/deployments/

# Ensure permissions are correct
RUN chown -R jboss:jboss /opt/jboss/wildfly && \
    chmod -R 755 /opt/jboss/wildfly

# Switch back to 'jboss' for security
USER jboss

# Set working directory
WORKDIR /opt/jboss/wildfly

# Limit Java memory (important for Render free tier)
ENV JAVA_OPTS="-Xms128m -Xmx256m"

# Expose the default WildFly port
EXPOSE 8080

# Start WildFly and bind it to all interfaces
CMD ["sh", "-c", "/opt/jboss/wildfly/bin/standalone.sh -b 0.0.0.0 -Djboss.http.port=${PORT:-8080}"]
