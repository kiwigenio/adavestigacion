import pandas as pd
import matplotlib.pyplot as plt

# 1. leer los datos del CSV
df = pd.read_csv('resultados_tiempos.csv')

# 2. tamano de la imagen 
plt.figure(figsize=(10, 6))

# 3. Dibujar las líneas: pasamos la columna X (N) y la columna Y (Tiempos)
plt.plot(df['num_pruebas'], df['Tiempo_Estandard'], linewidth=2, label='Método Estándar O(n^3)')
plt.plot(df['num_pruebas'], df['Tiempo_Strassen'], linewidth=2, label='Método Strassen O(n^2.81)')

# 4. Títulos y etiquetas descriptivas
plt.title('Comparación de Tiempos: Estándar vs Strassen', fontsize=14, fontweight='bold')
plt.xlabel('Tamaño de la Matriz (N)', fontsize=12)
plt.ylabel('Tiempo de Ejecución (segundos)', fontsize=12)

# 5. Escala Logarítmica 
plt.xscale('log', base=2)
plt.yscale('log')

# 6. agrega una leyenda y una cuadrícula de fondo
plt.legend(fontsize=11)
plt.grid(True, which="both", linestyle="--", alpha=0.7)

# 7. Guardar y Mostrar
plt.tight_layout() 
plt.savefig('grafica_n0.png', dpi=300)
plt.show() 