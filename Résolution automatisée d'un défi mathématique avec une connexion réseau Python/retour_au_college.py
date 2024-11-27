import socket
import math
import re
import time
import struct

def connect_and_compute():
    # Paramètres de connexion
    server_ip = 'adresse_serveur'
    server_port = numero_port
    
    # Créer une socket TCP/IP
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        # Se connecter au serveur
        sock.connect((server_ip, server_port))
        
        # Recevoir les données du serveur
        data = sock.recv(1024).decode('utf-8').strip()
        print(f"Données reçues : {data}")
        
        # Extraire les nombres à partir des données reçues
        try:
            # Utiliser une expression régulière pour extraire les nombres
            numbers = re.findall(r'\d+', data)
            if len(numbers) < 2:
                raise ValueError("Deux nombres non trouvés")
            
            # Prendre les deux derniers nombres extraits
            num1, num2 = map(float, numbers[-2:])
            print(f"Nombre 1 : {int(num1)}, Nombre 2 : {int(num2)}")
        except ValueError:
            print("Erreur : Les données reçues ne contiennent pas deux nombres valides.")
            return
        
        # Effectuer les calculs
        result = math.sqrt((num1)) * (num2)
        result = eval(round((result), 2))
        print(f"Résultat calculé : {result}")
        
        # Envoyer la réponse au serveur
        sock.send(str(result).encode() )      #client_socket.send(str(expression).encode())
        print("Réponse envoyée au serveur")
        
        # Attendre un peu pour s'assurer que la réponse est envoyée et une confirmation est reçue
        
        
        # Recevoir la confirmation du serveur
        confirmation = sock.recv(1024).decode()
        print("Réponse du serveur :", confirmation.decode('utf-8'))
    
    except Exception as e:
        print(f"Une erreur est survenue : {e}")
    
    finally:
        # Fermer la connexion
        sock.close()

