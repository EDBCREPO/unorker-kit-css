#pragma once

namespace uk { 

    express_tcp_t gap() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& size: map_t<string_t,int>({ 
                { nullptr,   0 },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"  },
                    { "2xsmall", "5px"  },
                    { "xsmall",  "10px" },
                    { "small",   "15px" },
                    { "medium",  "25px" },
                    { "large",   "30px" },
                    { "xlarge",  "35px" },
                    { "2xlarge", "40px" }
                }).data() ){ cli.write( regex::format( _STRING_(
                    .uk-child-gap-${0}${2}>:not([class*="uk-gap"]){ gap:${1}; } 
                    .uk-gap-${0}${2}                              { gap:${1}; }
                ), item.first, item.second, size.first )); }

                cli.write( regex::format( _STRING_( 
                   .uk-child-gap${0}>:not([class*="uk-gap"]){ gap:20px; }
                   .uk-gap${0}                              { gap:20px; } 
                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}