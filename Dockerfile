# Use official WildFly (JBoss) base image
FROM quay.io/wildfly/wildfly:latest

# Switch to root to fix permissions
USER root

# Copy everything into the WildFly directory
COPY . /opt/jboss/wildfly/

# Give full ownership of everything to the 'jboss' user
RUN chown -R jboss:jboss /opt/jboss/wildfly && \
    chmod -R 755 /opt/jboss/wildfly

# Switch back to jboss user for security
USER jboss

# Set the working directory
WORKDIR /opt/jboss/wildfly

# Limit Java memory (important for Render free tiers)
ENV JAVA_OPTS="-Xms256m -Xmx768m"

# Expose the default WildFly port
EXPOSE 8080

# Start WildFly and bind it to all interfaces
CMD ["sh", "-c", "/opt/jboss/wildfly/bin/standalone.sh -b 0.0.0.0 -Djboss.http.port=${PORT:-8080}"]
