# Run in the foreground to keep the container running:

background=NO

# Allow anonymous FTP? (Beware - allowed by default if you comment this out).

anonymous_enable=NO

# Uncomment this to allow local users to log in.

local_enable=YES

## Enable virtual users

guest_enable=NO

# Uncomment this to enable any form of FTP write command.

write_enable=YES

local_umask=022

passwd_chroot_enable=YES #리눅스 격리기술로, FTP에서 사용자들의 활동범위를 제한하는데 사용한다.

# enable passive mode #액티브는 서버가 클라이언트에게 파일을 보내고, 패시브는 클라이언트가 서버에서 직접 파일을 가져감.

pasv_enable=YES  
pasv_min_port=30020
pasv_max_port=30021 #ftp에 쓰이는게 30020~30029까지 포트임.
pasv_address=192.168.99.107 #dumy 파일, 이따가 sed로 바꿔줄 것.

# You may specify an explicit list of local users to chroot() to their home

# directory. If chroot_local_user is YES, then this list becomes a list of

# users to NOT chroot().

chroot_local_user=YES

# Workaround chroot check.

# See https://www.benscobie.com/fixing-500-oops-vsftpd-refusing-to-run-with-writable-root-inside-chroot/

# and http://serverfault.com/questions/362619/why-is-the-chroot-local-user-of-vsftpd-insecure

allow_writeable_chroot=YES

## Hide ids from user

hide_ids=YES

## Enable logging

xferlog_enable=YES
xferlog_file=/var/log/vsftpd.log
xferlog_std_format=No
log_ftp_protocol=YES

## Enable active mode

port_enable=YES
connect_from_port_20=YES
ftp_data_port=20

## Disable seccomp filter sanboxing

seccomp_sandbox=NO

# SSL SETTINGS

force_local_data_ssl=YES
force_local_logins_ssl=YES
rsa_cert_file=/etc/vsftpd/vsftpd.crt
rsa_private_key_file=/etc/vsftpd/vsftpd.key
ssl_enable=YES

require_ssl_reuse=YES
ssl_ciphers=HIGH

ssl_tlsv1=NO
ssl_sslv2=NO
ssl_sslv3=NO

virtual_use_local_privs=YES
listen_port=21

[참고](http://vsftpd.beasts.org/vsftpd_conf.html)
