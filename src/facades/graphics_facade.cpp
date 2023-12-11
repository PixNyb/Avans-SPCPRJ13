/**
 * @file graphics_facade.cpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the GraphicsFacade class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "graphics_facade.hpp"
#include "core_constants.hpp"
#include "sdl_circle.hpp"
#include "sdl_colors.hpp"
#include "sdl_rect.hpp"
#include "sdl_triangle.hpp"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

GraphicsFacade::GraphicsFacade()
{
    try
    {
        SdlInit = std::make_unique<SDLInit>();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception during GraphicsFacade initialization: " << e.what() << std::endl;
    }
}

GraphicsFacade::~GraphicsFacade() {}

void GraphicsFacade::Init() {}

void GraphicsFacade::PollEvents(std::vector<Event> &events)
{
    // implement features
}

void GraphicsFacade::CreateWindow(const std::string &title, int width, int height)
{
    const char *c_title = title.c_str();
    if (!SdlWindow)
    {
        SdlWindow = std::make_unique<SDLWindow>(c_title, width, height);
    }
    SdlWindow->Create(c_title, width, height);
}

void GraphicsFacade::ClearScreen()
{
    if (SdlWindow)
    {
        SdlWindow->ClearScreen();
    }
}

void GraphicsFacade::CreateRenderer()
{
    if (SdlWindow)
    {
        SdlWindow->CreateRenderer();
    }
}

void GraphicsFacade::PresentScreen()
{
    if (SdlWindow)
    {
        SdlWindow->PresentScreen();
    }
}

void GraphicsFacade::Delay(unsigned int ms)
{
    if (SdlWindow)
    {
        SdlWindow->Delay(ms);
    }
}

void GraphicsFacade::DrawShape(Circle circle)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    const Vector2D &pos = circle.GetPosition();
    int x = static_cast<int>(pos.x);
    int y = static_cast<int>(pos.y);
    int rad = static_cast<int>(circle.GetRadius());

    SetColor(circle.SetFillColor());
    SDLCircle sdlCircle(x, y, rad);
    sdlCircle.Draw(renderer);
    ResetColor();
}

void GraphicsFacade::DrawShape(Rectangle rectangle)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    const Vector2D &pos = rectangle.GetPosition();

    SDLRect rect(static_cast<int>(pos.x), static_cast<int>(pos.y), rectangle.GetWidth(),
                 rectangle.GetHeight(), static_cast<int>(rectangle.GetRotation()));

    SetColor(rectangle.SetFillColor());

    rect.Draw(renderer);
    ResetColor();
}

void GraphicsFacade::DrawShape(Triangle triangle)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    // Retrieve the vertices of the Triangle
    const Vector2D &v1 = triangle.GetVertex1();
    const Vector2D &v2 = triangle.GetVertex2();
    const Vector2D &v3 = triangle.GetVertex3();

    // Convert the vertices to the format expected by SDLTriangle
    auto x1 = static_cast<Sint16>(v1.x);
    auto y1 = static_cast<Sint16>(v1.y);
    auto x2 = static_cast<Sint16>(v2.x);
    auto y2 = static_cast<Sint16>(v2.y);
    auto x3 = static_cast<Sint16>(v3.x);
    auto y3 = static_cast<Sint16>(v3.y);

    // Apply rotation
    auto rotation = triangle.GetRotation();
    x1 = static_cast<Sint16>(x1 * cos(rotation) - y1 * sin(rotation));
    y1 = static_cast<Sint16>(x1 * sin(rotation) + y1 * cos(rotation));
    x2 = static_cast<Sint16>(x2 * cos(rotation) - y2 * sin(rotation));
    y2 = static_cast<Sint16>(x2 * sin(rotation) + y2 * cos(rotation));
    x3 = static_cast<Sint16>(x3 * cos(rotation) - y3 * sin(rotation));
    y3 = static_cast<Sint16>(x3 * sin(rotation) + y3 * cos(rotation));

    // Create an SDLTriangle with the converted vertices
    SDLTriangle sdlTriangle(x1, y1, x2, y2, x3, y3);

    // Use SDLTriangle's Draw method to render the triangle
    auto color = triangle.SetFillColor();
    SetColor(color);
    sdlTriangle.Draw(renderer);
    ResetColor();
}

void GraphicsFacade::DrawLine(Line line)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    // Apply rotation
    auto rotation = line.GetRotation();
    auto x1 = static_cast<Sint16>(line.start.x * cos(rotation) - line.start.y * sin(rotation));
    auto y1 = static_cast<Sint16>(line.start.x * sin(rotation) + line.start.y * cos(rotation));
    auto x2 = static_cast<Sint16>(line.end.x * cos(rotation) - line.end.y * sin(rotation));
    auto y2 = static_cast<Sint16>(line.end.x * sin(rotation) + line.end.y * cos(rotation));
    line.start.x = x1;
    line.start.y = y1;
    line.end.x = x2;
    line.end.y = y2;

    auto color = line.SetFillColor();
    SetColor(color);
    SDL_RenderDrawLine(renderer, line.start.x, line.start.y, line.end.x, line.end.y);
    ResetColor();
}

void GraphicsFacade::DrawLines(std::vector<Line> lines)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    auto sdlLines = std::vector<SDL_Point>();
    for (auto &line : lines)
    {
        // Apply rotation
        auto rotation = line.GetRotation();
        auto x1 = static_cast<Sint16>(line.start.x * cos(rotation) - line.start.y * sin(rotation));
        auto y1 = static_cast<Sint16>(line.start.x * sin(rotation) + line.start.y * cos(rotation));
        auto x2 = static_cast<Sint16>(line.end.x * cos(rotation) - line.end.y * sin(rotation));
        auto y2 = static_cast<Sint16>(line.end.x * sin(rotation) + line.end.y * cos(rotation));
        sdlLines.push_back({x1, y1});
        sdlLines.push_back({x2, y2});
    }

    auto color = lines[0].SetFillColor();
    SetColor(color);
    SDL_RenderDrawLines(renderer, sdlLines.data(), lines.size());
    ResetColor();
}

void GraphicsFacade::ResetColor()
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    // Reset the color for filling
    auto defaultColor = CoreConstants::Renderer::DEFAULT_RENDER_COLOR;
    auto colors = SDLColorUtility::GetSDLColor(defaultColor);
    SDL_SetRenderDrawColor(renderer, colors.r, colors.g, colors.b, colors.a);
}

void GraphicsFacade::SetColor(Color color)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    auto colors = SDLColorUtility::GetSDLColor(color);
    SDL_SetRenderDrawColor(renderer, colors.r, colors.g, colors.b, colors.a);
}

// TODO: Implement font manager?
void GraphicsFacade::DrawText(const Text &text)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    // Load the font
    auto fontPath = CoreConstants::Text::DEFAULT_FONT_PATH;

    auto sdlFont = TTF_OpenFont(fontPath.c_str(), text.GetFontSize());
    if (!sdlFont)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    // Create the text surface
    auto sdlColor = SDLColorUtility::GetSDLColor(text.GetTextColor());

    // Note: For some odd reason wrap length works in pixels instead of characters
    auto textSurface =
        TTF_RenderUTF8_Blended_Wrapped(sdlFont, text.GetText().c_str(), sdlColor, text.GetWidth());
    if (!textSurface)
    {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    // Limit height to text height if it's larger than the height
    if (textSurface->h > text.GetHeight())
    {
        textSurface->h = text.GetHeight();
    }

    // Create the text texture
    auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture)
    {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        return;
    }

    // Create the text rectangle
    auto position = text.GetTransform().position;
    auto textRect = SDL_Rect{static_cast<int>(position.x), static_cast<int>(position.y),
                             textSurface->w, textSurface->h};

    // Render the text
    SDL_RenderCopyEx(renderer, textTexture, nullptr, &textRect, text.GetTransform().rotation,
                     nullptr, SDL_FLIP_NONE);

    // Free the text surface and texture
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    // Close the font
    TTF_CloseFont(sdlFont);
}

void GraphicsFacade::DrawSprite(const Texture &texture, Rectangle &rectangle, bool flipX,
                                bool flipY)
{
    // Check if the texture has already been created and cached
    SDL_Texture *sdlTexture = GetCachedSDLTexture(texture);

    if (!sdlTexture)
    {
        // If not cached, create it and cache it
        sdlTexture = CreateSDLTextureFromTexture(texture);
        CacheSDLTexture(texture, sdlTexture);
    }
    // Proceed to draw the sprite using sdlTexture
    RenderSDLTexture(sdlTexture, rectangle, flipX, flipY);
}

void GraphicsFacade::RenderSDLTexture(SDL_Texture *sdlTexture, Rectangle rectangle, bool flipX,
                                      bool flipY)
{
    if (!sdlTexture)
    {
        std::cerr << "SDL_Texture is null" << std::endl;
        return;
    }

    SDL_Renderer *renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return;
    }

    // Extract position and size from the Rectangle object
    const Vector2D &pos = rectangle.GetPosition();
    int width = rectangle.GetWidth();
    int height = rectangle.GetHeight();

    // Define the SDL_Rect for rendering
    SDL_Rect sdlRect;
    sdlRect.x = static_cast<int>(pos.x);
    sdlRect.y = static_cast<int>(pos.y);
    sdlRect.w = width;
    sdlRect.h = height;

    if (flipX && flipY)
    {
        if (SDL_RenderCopyEx(
                renderer, sdlTexture, NULL, &sdlRect, 0, NULL,
                static_cast<const SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)) != 0)
        {
            std::cerr << "SDL_RenderCopy failed: " << SDL_GetError() << std::endl;
        }
    }
    else if (flipX && !flipY)
    {
        if (SDL_RenderCopyEx(renderer, sdlTexture, NULL, &sdlRect, 0, NULL, SDL_FLIP_HORIZONTAL) !=
            0)
        {
            std::cerr << "SDL_RenderCopy failed: " << SDL_GetError() << std::endl;
        }
    }
    else if (!flipX && flipY)
    {
        if (SDL_RenderCopyEx(renderer, sdlTexture, NULL, &sdlRect, 0, NULL, SDL_FLIP_VERTICAL) != 0)
        {
            std::cerr << "SDL_RenderCopy failed: " << SDL_GetError() << std::endl;
        }
    }
    else
    {
        if (SDL_RenderCopy(renderer, sdlTexture, NULL, &sdlRect) != 0)
        {
            std::cerr << "SDL_RenderCopy failed: " << SDL_GetError() << std::endl;
        }
    }
    // Render the texture to the screen
}

SDL_Texture *GraphicsFacade::GetCachedSDLTexture(const Texture &texture)
{
    auto it = textureCache.find(texture.getFilePath());
    if (it != textureCache.end())
    {
        return it->second;
    }
    return nullptr;
}

SDL_Texture *GraphicsFacade::CreateSDLTextureFromTexture(const Texture &texture)
{
    auto renderer = SdlWindow->GetRenderer();
    if (!renderer)
    {
        std::cerr << "Renderer is null" << std::endl;
        return nullptr;
    }
    SDL_Surface *surface = IMG_Load(texture.getFilePath().c_str());
    if (!surface)
    {
        // Handle error
        return nullptr;
    }

    SDL_Texture *sdlTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!sdlTexture)
    {
        std::cerr << "SDLTexture error" << std::endl;
        return nullptr;
    }

    return sdlTexture;
}

void GraphicsFacade::CacheSDLTexture(const Texture &texture, SDL_Texture *sdlTexture)
{
    textureCache[texture.getFilePath()] = sdlTexture;
}

Size GraphicsFacade::GetSpriteSize(const std::string &filePath)
{
    SDL_Surface *surface = IMG_Load(filePath.c_str());
    if (!surface)
    {
        std::cerr << "Unable to load image: " << filePath << std::endl;
        return Size{0, 0}; // Return an empty size if the image fails to load
    }

    Size size = {surface->w, surface->h};
    SDL_FreeSurface(surface);
    return size;
}

void GraphicsFacade::DrawSpriteSheetFrame(const Texture &texture, const Rectangle &dstRect,
                                          int frameIndex, int totalColumns, int totalRows,
                                          bool flipX, bool flipY, double angle)
{
    SDL_Texture *sdlTexture = GetCachedSDLTexture(texture);
    if (!sdlTexture)
    {
        sdlTexture = CreateSDLTextureFromTexture(texture);
        CacheSDLTexture(texture, sdlTexture);
    }

    if (!sdlTexture)
    {
        std::cerr << "SDL_Texture is null for sprite sheet frame" << std::endl;
        return;
    }

    // Calculate the source rectangle for the current frame
    int frameWidth, frameHeight;
    SDL_QueryTexture(sdlTexture, NULL, NULL, &frameWidth, &frameHeight);
    frameWidth /= totalColumns;
    frameHeight /= totalRows;

    SDL_Rect srcRect;
    srcRect.x = (frameIndex % totalColumns) * frameWidth;
    srcRect.y = (frameIndex / totalColumns) * frameHeight;
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;

    // Define the destination SDL_Rect for rendering
    SDL_Rect sdlDstRect = {static_cast<int>(dstRect.GetPosition().x),
                           static_cast<int>(dstRect.GetPosition().y), dstRect.GetWidth(),
                           dstRect.GetHeight()};

    // Determine the flipping mode
    SDL_RendererFlip flip = static_cast<SDL_RendererFlip>((flipX ? SDL_FLIP_HORIZONTAL : 0) |
                                                          (flipY ? SDL_FLIP_VERTICAL : 0));

    // Render the frame with rotation and flipping
    if (SDL_RenderCopyEx(SdlWindow->GetRenderer(), sdlTexture, &srcRect, &sdlDstRect, angle, NULL,
                         flip) != 0)
    {
        std::cerr << "SDL_RenderCopyEx failed: " << SDL_GetError() << std::endl;
    }
}
