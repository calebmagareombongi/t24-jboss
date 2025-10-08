# Use official Red Hat JBoss EAP base image (or generic openjdk)
FROM openjdk:11

# Set working directory
WORKDIR /opt/jboss

# Copy all files to container
COPY . .

# Expose JBoss default port
EXPOSE 8080

# Start JBoss using your .bat equivalent for Linux
CMD ["sh", "bin/standalone.sh", "-b", "0.0.0.0"]
