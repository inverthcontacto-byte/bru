<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Para Brune ❤️</title>
  <style>
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
    }

    body {
      min-height: 100vh;
      overflow: hidden;
      background: radial-gradient(circle at center, #1a0010 0%, #050005 45%, #000 100%);
      font-family: 'Segoe UI', Arial, sans-serif;
      color: white;
    }

    .container {
      position: relative;
      width: 100vw;
      height: 100vh;
      display: flex;
      align-items: center;
      justify-content: center;
      text-align: center;
      overflow: hidden;
    }

    .glow {
      position: absolute;
      width: 460px;
      height: 460px;
      background: radial-gradient(circle, rgba(255, 0, 110, 0.32), transparent 68%);
      filter: blur(12px);
      animation: glowPulse 2.2s infinite ease-in-out;
    }

    .content {
      position: relative;
      z-index: 10;
      display: flex;
      flex-direction: column;
      align-items: center;
      gap: 24px;
      padding: 20px;
    }

    .heart {
      position: relative;
      width: 155px;
      height: 155px;
      background: linear-gradient(135deg, #ff005d, #ff3b8d, #ff7ab8);
      transform: rotate(-45deg);
      animation: heartbeat 1.25s infinite ease-in-out;
      box-shadow: 0 0 35px #ff006a, 0 0 80px rgba(255, 0, 120, 0.65);
    }

    .heart::before,
    .heart::after {
      content: '';
      position: absolute;
      width: 155px;
      height: 155px;
      background: inherit;
      border-radius: 50%;
    }

    .heart::before {
      top: -77px;
      left: 0;
    }

    .heart::after {
      left: 77px;
      top: 0;
    }

    h1 {
      font-size: clamp(2.2rem, 8vw, 5.3rem);
      letter-spacing: 1px;
      text-shadow: 0 0 12px #ff4f9a, 0 0 30px #ff0066, 0 0 55px #ff0066;
      animation: textPulse 2s infinite ease-in-out;
    }

    .subtitle {
      font-size: clamp(1rem, 3vw, 1.45rem);
      opacity: 0.86;
      text-shadow: 0 0 12px rgba(255, 255, 255, 0.4);
    }

    .floating-heart {
      position: absolute;
      bottom: -40px;
      color: #ff4f9a;
      animation: floatUp linear forwards;
      filter: drop-shadow(0 0 8px #ff006a);
      opacity: 0.85;
      user-select: none;
      pointer-events: none;
    }

    .particle {
      position: absolute;
      font-size: 22px;
      pointer-events: none;
      user-select: none;
      animation: explode 900ms ease-out forwards;
      filter: drop-shadow(0 0 8px #ff006a);
    }

    .tap-text {
      position: absolute;
      bottom: 24px;
      left: 50%;
      transform: translateX(-50%);
      z-index: 20;
      font-size: 0.95rem;
      opacity: 0.7;
      animation: fadeTap 2s infinite;
    }

    @keyframes heartbeat {
      0%, 100% { transform: rotate(-45deg) scale(1); }
      15% { transform: rotate(-45deg) scale(1.16); }
      30% { transform: rotate(-45deg) scale(1); }
      45% { transform: rotate(-45deg) scale(1.10); }
      60% { transform: rotate(-45deg) scale(1); }
    }

    @keyframes glowPulse {
      0%, 100% { transform: scale(1); opacity: 0.7; }
      50% { transform: scale(1.2); opacity: 1; }
    }

    @keyframes textPulse {
      0%, 100% { transform: scale(1); }
      50% { transform: scale(1.035); }
    }

    @keyframes floatUp {
      0% {
        transform: translateY(0) rotate(0deg) scale(0.7);
        opacity: 0;
      }
      10% { opacity: 0.95; }
      100% {
        transform: translateY(-115vh) rotate(360deg) scale(1.4);
        opacity: 0;
      }
    }

    @keyframes explode {
      0% {
        transform: translate(0, 0) scale(0.4) rotate(0deg);
        opacity: 1;
      }
      100% {
        transform: translate(var(--x), var(--y)) scale(1.45) rotate(360deg);
        opacity: 0;
      }
    }

    @keyframes fadeTap {
      0%, 100% { opacity: 0.42; }
      50% { opacity: 0.9; }
    }

    @media (max-width: 600px) {
      .heart {
        width: 115px;
        height: 115px;
      }

      .heart::before,
      .heart::after {
        width: 115px;
        height: 115px;
      }

      .heart::before {
        top: -57px;
      }

      .heart::after {
        left: 57px;
      }

      .glow {
        width: 320px;
        height: 320px;
      }
    }
  </style>
</head>
<body>
  <div class="container" id="container">
    <div class="glow"></div>

    <div class="content">
      <div class="heart"></div>
      <h1>Te amo mucho Brune</h1>
      <p class="subtitle">Este link es solo para vos ❤️</p>
    </div>

    <p class="tap-text">Tocá la pantalla ✨</p>
  </div>

  <script>
    const container = document.getElementById('container');
    const heartSymbols = ['❤️', '💖', '💕', '💗', '💘', '💞'];

    function createFloatingHeart() {
      const heart = document.createElement('div');
      heart.className = 'floating-heart';
      heart.textContent = heartSymbols[Math.floor(Math.random() * heartSymbols.length)];
      heart.style.left = Math.random() * 100 + 'vw';
      heart.style.fontSize = Math.random() * 22 + 16 + 'px';
      heart.style.animationDuration = Math.random() * 3 + 4 + 's';
      container.appendChild(heart);

      setTimeout(() => heart.remove(), 7500);
    }

    function createExplosion(x, y) {
      for (let i = 0; i < 32; i++) {
        const particle = document.createElement('div');
        particle.className = 'particle';
        particle.textContent = heartSymbols[Math.floor(Math.random() * heartSymbols.length)];
        particle.style.left = x + 'px';
        particle.style.top = y + 'px';

        const angle = Math.random() * Math.PI * 2;
        const distance = Math.random() * 180 + 55;
        const moveX = Math.cos(angle) * distance;
        const moveY = Math.sin(angle) * distance;

        particle.style.setProperty('--x', moveX + 'px');
        particle.style.setProperty('--y', moveY + 'px');
        particle.style.fontSize = Math.random() * 18 + 18 + 'px';

        container.appendChild(particle);
        setTimeout(() => particle.remove(), 950);
      }
    }

    container.addEventListener('click', (event) => {
      createExplosion(event.clientX, event.clientY);
    });

    container.addEventListener('touchstart', (event) => {
      const touch = event.touches[0];
      createExplosion(touch.clientX, touch.clientY);
    });

    setInterval(createFloatingHeart, 220);

    setInterval(() => {
      createExplosion(window.innerWidth / 2, window.innerHeight / 2);
    }, 2600);
  </script>
</body>
</html>

