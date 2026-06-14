//So this code is for the backend rotuing and that stuff for my project --> Have it locally on my pc
const express = require('express');
const cors = require('cors');
const fs = require('fs');
const path = require('path');
const { createClient } = require('@supabase/supabase-js');

const app = express();
const PORT = 8080;

//SUPABASE CONFIGURATION
// Replace these with  actual keys
const SUPABASE_URL = 'YOUR_SUPABASE_PROJECT_URL';
const SUPABASE_KEY = 'YOUR_SUPABASE_ANON_KEY';

const supabase = createClient(SUPABASE_URL, SUPABASE_KEY);


app.use(cors());

// Ensure local folder exists for live UI tracking feed
const dir = './temp_frames';
if (!fs.existsSync(dir)){
    fs.mkdirSync(dir);
}



// Main intake route for the physical hardware station
app.post('/upload-frame', (req, res) => {
    const weight = req.headers['x-weight-grams'] || 0;
    const crop = req.headers['x-crop-type'] || 'unknown';

    console.log(`Received Hardware Intake: Weight = ${weight}g, Crop = ${crop}`);

    const targetPath = path.join(__dirname, 'temp_frames', 'test.jpg');
    const imageBuffer = [];

    req.on('data', chunk => {
        imageBuffer.push(chunk);
    });

    req.on('end', () => {
        fs.writeFileSync(targetPath, Buffer.concat(imageBuffer));
        console.log('Frame written to local cache.');

        // Stream telemetric payload to Supabase matching SQL database scheme --> this stufff wea kinda tough for me so hopefully it works
        supabase
            .from('harvest_logs')
            .insert([
                { 
                    weight_grams: parseFloat(weight), 
                    crop_type: crop, 
                    image_path: 'temp_frames/test.jpg' 
                }
            ])
            .then(({ error }) => {
                if (error) {
                    console.error('Database Sync Error:', error.message);
                } else {
                    console.log('Telemetry logged to Supabase Cloud.');
                }
            });

        res.send('Frame processed.');
    });
});

// Endpoint for frontend dashboard UI to grab the fresh camera layout
app.get('/live-frame', (req, res) => {
    const filePath = path.join(__dirname, 'temp_frames', 'test.jpg');
    if (fs.existsSync(filePath)) {
        res.sendFile(filePath);
    } else {
        res.status(404).send('No frame uploaded yet.');
    }
});

//Start and tell me its actually working
app.listen(PORT, () => {
    console.log(`=================================================`);
    console.log(`   HARVEST AI PRODUCTION BACKEND ONLINE ON: ${PORT} `);
    console.log(`=================================================`);
});
