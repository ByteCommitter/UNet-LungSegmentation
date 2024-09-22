# U-Net Image Segmentation for Chest X-Ray Images

I am currently having the wonderful opportunity to work under Rajesh sir (GitHub ID: [tripathy12345](https://github.com/tripathy12345)), on this project.

We are focusing on implementing a U-Net model for segmenting lung outlines in chest X-ray images.
## Features
- U-Net architecture for image segmentation
- Data augmentation techniques to enhance model robustness
- Evaluation metrics including accuracy, precision, recall, F1 score, and IoU

## Outputs of segmenting the images:
![image](https://github.com/user-attachments/assets/b38fd32e-03fa-4da1-ac34-2f5528feca0c)

![image](https://github.com/user-attachments/assets/99543323-3e7f-4987-b29d-69d9d7d70890)

![image](https://github.com/user-attachments/assets/2842694d-9387-4309-ac84-a66d9d71a166)

![image](https://github.com/user-attachments/assets/6c0c9821-a48b-4384-a3e3-ab75bf84f6a3)



## Model's Peformance Metrics:

Accuracy: 0.9806
Precision: 0.9708
Recall: 0.9538
F1-Score: 0.9623
IoU: 0.9273
Dice Coefficient: 0.9623


# Multi-Frequency UNet and FB2DEWT Components
The FB2DEWT components are used to generate 10 different components of the same image. We then use this to train UNet.
I modified the exisitng pipeline I had created using Transform Images Notebook, to directly use the components created by the FB2WEDT transformation.  This was a much more creative and effecient approach to solve the problem. So everytime an image was called for training, it would generate the components which would then be fed into the modified UNet


## FB2DEWT Components:
FB2DEWT components are used to generate 10 frequency bands from a single grayscale image. These components capture multi-frequency information, which can enhance the model’s ability to segment features across different spatial frequencies.

## Pipeline:
The training pipeline is designed to dynamically generate FB2DEWT components during the training process. Rather than relying on precomputed data, the transformation is applied in real-time, ensuring efficient memory usage and better adaptability.

### Pipeline Modifications:
Initially, we tried saving all the .npy files produced from the components, but this approach presented several challenges. The generation of .npy files took significant time and storage. Given my limited computational resources, this led to data loss, a much smaller dataset, and inefficient training cycles with poor results.

To resolve these issues, I modified the existing pipeline (created using the Transform Images Notebook) to dynamically generate the FB2DEWT components during training, avoiding the need to store large .npy files. This creative and efficient solution allowed the training process to proceed without size limitations and improved performance.

However, during model integration, we initially encountered issues with the UNet producing blank predictions. This was resolved by adjusting the model input handling and fine-tuning the learning process.


## Key Modifications:
On-the-Fly Component Generation: Every time an image is loaded for training, 10 frequency components are generated using FB2DEWT and passed into the UNet.
Modified UNet: The standard UNet was adjusted to accept multi-channel input (10 channels), corresponding to the FB2DEWT components.
##### Performance Focus:
The pipeline optimizes both computational efficiency and model accuracy by leveraging frequency domain representations of the input images.
This approach provides a creative and efficient solution for lung segmentation, offering flexibility for real-time data handling and adaptability to different image transformation techniques.



## Challenges Faced Implemented Approaches So Far:

### FB2DEWT Component Generation:

We initially generated and stored the 10 components of each image using FB2DEWT and saved them as .npy files.
This approach was inefficient, consuming a lot of time and storage, ultimately leading to data loss and a very small dataset.
Pipeline Modification:

Switched to generating FB2DEWT components dynamically during training, which avoided the need for large .npy file storage.
This allowed the training process to handle the data without size limitations, but some challenges persisted.
Initial UNet Model Integration:

Integrated the 10 generated components into the UNet model's input pipeline.
Despite the pipeline working, predictions resulted in blank or black images, suggesting the model wasn’t learning effectively from the components.

### Updated Strategy:
 
 #### Direct Component Generation During Training:

Instead of saving .npy files, components are now generated on the fly during each training step.
This ensures data integrity, eliminates storage issues, and makes the process more efficient.
Tuning and Debugging Model Training:

Currently, we're refining the model's learning strategy, as initial predictions were poor, likely due to improper component scaling or network tuning.
