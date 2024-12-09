#pragma once

namespace uk { 

    express_tcp_t text() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();
            
            forEach( item, ptr_t<string_t>({
                "none", "blink", "dashed", "dotted", "solid", "double", "wavy", "overline", "undeline"
            })){
                cli.write( regex::format( _STRING_(
                   .uk-text-decoration-${0} { text-decoration: ${0}; }
                ), item ));
            }
            
            forEach( item, ptr_t<string_t>({ "left", "right", "center", "justify" })){
                cli.write( regex::format( _STRING_(
                   .uk-text-${0} { text-align: ${0}; }
                ), item ));
            }
            
            forEach( color, ptr_t<string_t>({
                "primary", "secondary", "success",
                "warning", "danger"   , "mute"   ,
                "dark"   , "light"    , "neutral"
            })){
                cli.write( regex::format( _STRING_(
                   .uk-placeholder-${0}::placeholder { color: var(--${0}) !important; }
                   .uk-text-hover-${0}:hover         { color: var(--${0}) !important; }
                   .uk-text-${0}                     { color: var(--${0}) !important; }
                ), color ));
            }

            cli.write( _STRING_(

                .uk-text-lead       { font-size: 1.5rem; line-height: 1.5; }
                .uk-text-italic     { font-style: italic; }

                .uk-text-light      { font-weight: 300; }
                .uk-text-normal     { font-weight: 400; }
                .uk-text-bold       { font-weight: 700; }
                .uk-text-bolder     { font-weight: bolder; }
                .uk-text-lighter    { font-weight: lighter; }
                
                .uk-text-lowecase   { text-transform: lowecase; }
                .uk-text-uppercase  { text-transform: uppercase; }
                .uk-text-capitalize { text-transform: capitalize; }

            ));

        });

        return app;
    }

}