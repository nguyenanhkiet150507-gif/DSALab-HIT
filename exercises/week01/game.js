const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");

// Khởi tạo quả bóng
let ballX = canvas.width / 2;
let ballY = canvas.height / 2;
let ballSpeedX = 5;
let ballSpeedY = -5;
const ballRadius = 10;

// Khởi tạo thanh đỡ
const paddleWidth = 150;
const paddleHeight = 15;
let paddleX = (canvas.width - paddleWidth) / 2;

// Lắng nghe sự kiện di chuyển chuột để điều khiển thanh đỡ
canvas.addEventListener("mousemove", (e) => {
    const rect = canvas.getBoundingClientRect();
    paddleX = e.clientX - rect.left - paddleWidth / 2;
});

// Vòng lặp chính của Game (Game Loop)
function update() {
    // 1. Cập nhật vị trí bóng
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // 2. Xử lý va chạm với tường trái/phải
    if (ballX - ballRadius < 0 || ballX + ballRadius > canvas.width) {
        ballSpeedX = -ballSpeedX;
    }
    // Xử lý va chạm với trần nhà
    if (ballY - ballRadius < 0) {
        ballSpeedY = -ballSpeedY;
    }

    // 3. Xử lý va chạm với thanh đỡ hoặc rớt xuống dưới
    if (ballY + ballRadius > canvas.height - paddleHeight) {
        if (ballX > paddleX && ballX < paddleX + paddleWidth) {
            ballSpeedY = -ballSpeedY; // Nảy lên lại
        } else if (ballY - ballRadius > canvas.height) {
            // Thua game, reset lại bóng
            ballX = canvas.width / 2;
            ballY = canvas.height / 2;
            ballSpeedY = -5;
        }
    }

    // 4. Xóa màn hình cũ và vẽ lại mọi thứ
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Vẽ quả bóng
    ctx.beginPath();
    ctx.arc(ballX, ballY, ballRadius, 0, Math.PI * 2);
    ctx.fillStyle = "#ff4757";
    ctx.fill();
    ctx.closePath();

    // Vẽ thanh đỡ
    ctx.fillStyle = "#2ed573";
    ctx.fillRect(paddleX, canvas.height - paddleHeight, paddleWidth, paddleHeight);

    // Gọi lại hàm update liên tục để tạo chuyển động mượt mà
    requestAnimationFrame(update);
}

// Bắt đầu chạy game
update();