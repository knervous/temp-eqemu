ALTER TABLE login_accounts MODIFY COLUMN last_ip_address VARCHAR(30) NOT NULL;
ALTER TABLE login_server_admins MODIFY COLUMN registration_ip_address VARCHAR(30) NOT NULL;
ALTER TABLE login_world_servers MODIFY COLUMN last_ip_address VARCHAR(30) DEFAULT NULL;
