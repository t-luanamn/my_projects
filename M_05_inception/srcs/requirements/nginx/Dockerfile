# Use Debian as the base image
FROM debian:bullseye

LABEL "author"="tluanamn"

# Install NGINX and required packages
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    curl \
    iputils-ping \
    && mkdir -p /run/nginx \
    && rm -rf /etc/nginx/sites-available/default.conf

# Create directory for SSL certificates
RUN mkdir -p /etc/nginx/ssl

# Generate self-signed certificates (replace with real certificates in production)
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/CN=tluanamn.42.fr"

# Copy custom NGINX configuration
COPY ./conf/default.conf /etc/nginx/sites-available/default.conf

RUN ln -s /etc/nginx/sites-available/default.conf /etc/nginx/sites-enabled/default.conf

# Expose port 443
EXPOSE 443

# Start NGINX in the foreground
CMD ["nginx", "-g", "daemon off;"]

# Verify NGINX Configuration:
#     docker exec -it nginx nginx -t
# Verify SSL/TLS Connection:
#     curl -v --tlsv1.3 https://tluanamn.42.fr
#     curl -v --tlsv1.3 -k https://tluanamn.42.fr
#     curl -v --tlsv1.3 --insecure https://tluanamn.42.fr
